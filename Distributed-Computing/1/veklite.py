#!/usr/bin/env python3

from re import match, split
from socket import socket, inet_aton, AF_INET, SOCK_STREAM, timeout, error
from sys import argv
from threading import Thread

def server(ip: str = "0.0.0.0", port: int = 5002):
	def _send(result: str):
		try:
			csock.send(result.encode("utf-8"))
		except timeout:
			print(f"{ps1} Connection timed out")
		except error:
			print(f"{ps1} Connection error")
	def _handler(csock: socket):
		while True:
			try:
				req = csock.recv(1024)
			except timeout:
				print("Connection timed out")
			except error:
				print("Connection error")
			if not req:
				print(f"{ps1} Connection closed")
				csock.close()
				return
			cmd = req.decode("utf-8")
			if not match(r"^(dot|cross)\s+(\d+,\d+,\d+)\s+(\d+,\d+,\d+)$", cmd):
				result = f"Unrecognized operation {cmd}"
				print(f"{ps1} {result}")
				_send(result = result)
				continue
			argv = split(r"\s+", cmd)
			vec1 = tuple(map(lambda x: float(x or 0), argv[1].strip(",").split(",")))
			vec2 = tuple(map(lambda x: float(x or 0), argv[2].strip(",").split(",")))
			if not len(vec1) == 3 or not len(vec2) == 3:
				result = f"Unsupported vector length {len(vec1)} and {len(vec2)}"
				print(f"{ps1} {result}")
				_send(result = result)
				continue
			if argv[0] == "dot":
				result = f"{sum(x * y for x, y in zip(vec1, vec2))}"
				print(f"{ps1} {result}")
				_send(result = result)
				continue
			if argv[0] == "cross":
				result = ",".join(map(str, (
					vec1[1] * vec2[2] - vec1[2] * vec2[1],
					vec1[2] * vec2[0] - vec1[0] * vec2[2],
					vec1[0] * vec2[1] - vec1[1] * vec2[0])
				))
				print(f"{ps1} {result}")
				_send(result = result)
				continue
	try:
		sock = socket(AF_INET, SOCK_STREAM)
		sock.settimeout(10)
		sock.bind((ip, port))
		sock.listen(10)
	except Exception:
		print("Failed to start server")
		return 1
	print(f"Server started successfully at {ip}:{port}")
	while True:
		try:
			csock, addr = sock.accept()
		except timeout:
			continue
		except error:
			print("Connection error")
			continue
		ps1 = f"[{":".join(map(str, addr))}]"
		print(f"{ps1} Connection established")
		Thread(target = _handler, kwargs = {"csock": csock}).start()

def client(ip: str = "127.0.0.1", port: int = 5002):
	try:
		sock = socket(AF_INET, SOCK_STREAM)
		sock.settimeout(10)
		sock.connect((ip, port))
	except Exception:
		print("Failed to connect to server")
		return 1
	print(f"Connected to server {ip}:{port}")
	while True:
		cmd = input(">>> ").strip()
		if match(r"^exit$", cmd):
			sock.close()
			return 0
		if match(r"^help$", cmd):
			print("dot <vec1> <vec2>      Calculate the dot product of two comma-seperated vectors with three elements")
			print("cross <vec1> <vec2>    Calculate the cross product of two comma-seperated vectors with three elements")
			print("help                   Show this help information")
			print("exit                   Exit the client")
			continue
		if not match(r"^(dot|cross)\s+(\d+,\d+,\d+)\s+(\d+,\d+,\d+)$", cmd):
			print(f"Unrecognized operation {cmd}")
			continue
		try:
			sock.send(cmd.encode("utf-8"))
			res = sock.recv(1024)
			print(res.decode("utf-8"))
		except timeout:
			print("Connection timed out")
		except error:
			print("Connection error")

def main():
	if not len(argv) > 1:
		print(f"No option specified")
		return 1
	if not argv[1] in ("server", "client", "help"):
		print(f"Unrecognized option {" ".join(argv[1 :])}")
		return 1
	if argv[1] == "help":
		print(f"Veklite - Vector Computing Tool by Pairman")
		print(f"Usage: {argv[0]} server <ip> <port>    Run a server binding specific ip and port")
		print(f"  or:  {argv[0]} client <ip> <port>    Open a client listening to specific and port")
		print(f"  or:  {argv[0]} help                  Show this help information")
		return 0
	ip, port = "0.0.0.0", 5002
	if len(argv) == 4:
		try:
			ip = argv[2]
			inet_aton(ip)
		except Exception:
			print(f"Invalid IP address {ip}")
			return 1
		try:
			port = int(argv[3])
			assert 0 < port < 65536
		except Exception:
			print(f"Invalid port number {port}")
			return 1
	return (server if argv[1] == "server" else client)(ip = ip, port = port)

if __name__ == "__main__":
	main()
