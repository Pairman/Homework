from asyncio import run as _run
from uuid import uuid4 as _uuid4
from websockets import WebSocketClientProtocol as _WebSocketClientProtocol, \
WebSocketServerProtocol as _WebSocketServerProtocol
from websockets.exceptions import WebSocketException as _WebSocketException
from visper.net.websocket import WebSocketSession as _WebSocketSession
from visper.util.time import time_ms as _time_ms, \
parse_time_ms as _parse_time_ms
from visper.core.message_types_pb2 import Body as _Body, \
Heartbeat as _Heartbeat, Proposal as _Proposal, Vote as _Vote, \
Result as _Result, Message as _Message

class Messenger:
	def __init__(self, ws_host: str, ws_port: str):
		"""Create a websocket wrapper session.
		:param host: The host to listen to.
		:param port: The port to listen to.
		:param client_handler: Handler for client connection.
		"""
		self.__wss = _WebSocketSession(host = ws_host, port = ws_port)
		self.__f___aenter__ = False

	async def __aenter__(self):
		if not self.__f___aenter__:
			await self.__wss.__aenter__()
			self.__f___aenter__ = True
		return self

	async def __aexit__(self, *args, **kwargs):
		if self.__f___aenter__:
			await self.__wss.__aexit__(*args, **kwargs)
			self.__f___aenter__ = False

	async def send(self, message: _Message, id: str):
		"""Send message to a client.
		:param message: The message.
		:param id: UUID of the client.
		:param websocket: Client websocket. Unused if ``id`` is present.
		"""
		await self.__wss.send(message = message, id = id)

	async def broadcast(self, message: bytes):
		"""Broadcast message to all clients.
		:param message: The message.
		"""
		await self.__wss.broadcast(message = message)

	def main_loop(self):
		_run(self.__main_loop())

	async def __main_loop(self):
		await self.__wss.__aenter__()
		pass

async def client_handler(
	session: _WebSocketSession,
	websocket: _WebSocketClientProtocol | _WebSocketServerProtocol
):
	"""Client handler for ``WebSocket``.
	:session: ``WebSocketSession`` instance.
	:websocket: Client websocket connection.
	"""
	try:
		session.msg_seq += 1
		message = _Message(proposal = _Proposal(
			msg_id = str(_uuid4()), sender_id = session.id,
			prev_sender_ids = [], topic = session.msg_seq,
			timestamp = _time_ms()
		))
		await session.send(message = message, websocket = websocket)
		message.parseFromString(
			await session.recv(websocket = websocket)
		)
		assert message.HasField("vote")
		### TODO: CONTINUE FROM HERE
		# HOW DO I GATHER VOTE VALUES FROM DIFFERENT CLIENTS?
		while True:
			message_bytes = await session.recv(websocket = websocket)
			time = _parse_time_ms(round(message_bytes.headers.time, 2))
			print(f"{time} {name}: {message_bytes.body}")
			await session.__messages.put(message_bytes)
		# TODO: broadcast max known message ids
		#       and other info (client ids, clocks, etc)
	except _WebSocketException:
		return