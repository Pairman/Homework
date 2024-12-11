from asyncio import create_task as _create_task, gather as _gather, \
Queue as _Queue
from uuid import uuid4 as _uuid4
from aiorwlock import RWLock as _RWLock
from websockets import connect as _connect, serve as _serve, \
WebSocketClientProtocol as _WebSocketClientProtocol, \
WebSocketServerProtocol as _WebSocketServerProtocol
from websockets.exceptions import WebSocketException as _WebSocketException
from visper.net.ip import resolve_ipaddr as _resolve_ipaddr
from visper.util.nickname import get_name as _get_name
from visper.util.time import time_ms as _time_ms
from visper.core.message_types_pb2 import Handshake as _Handshake, \
Message as _Message

class WebSocketSession:
	"""Websocket wrapper.
	"""

	def __init__(self, host: str, port: int):
		"""Create a websocket wrapper session.
		:param host: The host to listen to.
		:param port: The port to listen to.
		:param client_handler: Handler for client connection.
		"""
		self.id, self.name = str(_uuid4()), _get_name(self)
		self.__server_host, self.__server_port = host, port
		self.__wss, self.__wss_serve = None, None
		self.__clients_lock, self.client_status = _RWLock(), {}
		self.clients, self.client_names,  = {}, {}
		self.__messages, self.msg_seq = _Queue(), 0
		self.__f___aenter__ = False

	async def __client_handler(
		self,
		websocket: _WebSocketClientProtocol | _WebSocketServerProtocol
	):
		try:
			message = _Handshake(
				msg_seq = self.msg_seq, sender_id = self.id,
				sender_name = self.name, timestamp = _time_ms()
			)
			await self.send(
				message = message, websocket = websocket
			)
			message.ParseFromString(await websocket.recv())
			f_id_exists = False
			id = message.sender_id
			async with self.__clients_lock.reader_lock:
				if id in self.clients:
					f_id_exists = True
			if f_id_exists:
				await websocket.close()
				await websocket.wait_closed()
				return
			if self.msg_seq < message.msg_seq:
				self.msg_seq = message.msg_seq
			async with self.__clients_lock.writer_lock:
				self.clients[id] = websocket
				self.client_names[id] = message.sender_name
				self.client_timestamps[id] = message.timestamp
				self.client_status[id] = True
			while True:
				async with self.__clients_lock.reader_lock:
					status = self.client_status[id]
				if not status:
					break
				message = _Message()
				message.ParseFromString(await websocket.recv())
				self.__messages.put(message)
		except _WebSocketException:
			pass
		finally:
			async with self.__clients_lock.writer_lock:
				del self.clients[id], self.client_names[id]
				del self.client_status[id]
			await websocket.close()
			await websocket.wait_closed()
			return

	async def __aenter__(self):
		if not self.__f___aenter__:
			self.__wss_serve = _serve(
				self.__client_handler,
				self.__server_host, self.__server_port
			)
			self.__wss = await self.__wss_serve.__aenter__()
			self.__f___aenter__ = True
		return self

	async def __aexit__(self, *args, **kwargs):
		if self.__f___aenter__:
			await self.__wss_serve.__aexit__(*args, **kwargs)
			self.__f___aenter__ = False

	async def connect(self, host: str, port: int):
		"""Connect to a new client.
		:param host: Host of the client.
		:param port: Port of the client.
		"""
		af, addr = _resolve_ipaddr(host = host)
		if af == "AF_INET6":
			addr = f"[{addr}]"
		uri = f"ws://{addr}:{port}"
		try:
			websocket = await _connect(uri)
		except OSError as e:
			raise _WebSocketException(e.args)
		_create_task(self.__client_handler(websocket = websocket))

	async def disconnect(self, id: str):
		"""Disconnect from a client.
		:param id: UUID of the client.
		"""
		async with self.__clients_lock.writer_lock:
			self.client_status[id] = False

	async def receive(self):
		"""Receive message from all clients.
		:return: The message.
		"""
		return await self.__messages.get()

	async def send(
			self, message: _Message, id: str = "",
			websocket: _WebSocketClientProtocol |
			_WebSocketServerProtocol = None
		):
		"""Send message to a client.
		:param message: The message.
		:param id: UUID of the client.
		:param websocket: Client websocket. Unused if ``id`` is present.
		"""
		assert id or websocket
		if id:
			async with self.__clients_lock.reader_lock:
				websocket = self.clients[id].websocket
		await websocket.send(message.SerializeToString())

	async def broadcast(self, message: bytes):
		"""Broadcast message to all clients.
		:param message: The message.
		"""
		async with self.__clients_lock.reader_lock:
			_gather(*(
				self.send(
					message = message,
					websocket = client.websocket
				) for client in self.clients.values()
			))
