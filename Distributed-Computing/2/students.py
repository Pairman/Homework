#!/usr/bin/env python3

from re import match
from socket import socket, inet_aton, AF_INET, SOCK_STREAM, timeout, error
from sys import argv
from threading import Thread
from io import StringIO
from contextlib import redirect_stdout, redirect_stderr

class Student:
	id: int = 0
	name: str = ""

	def __init__(self, id: int = 0, name: str = "") -> None:
		self.id, self.name = int(id), str(name)

	def __repr__(self) -> str:
		return f"Student({self.id}, \"{self.name}\")"

class Students:
	students: dict[Student] = {}

	def __init__(self, students: dict[Student] = {}) -> None:
		self.students = students

	def __repr__(self) -> str:
		return f"Students({{{', '.join(map(str, self.students.values()))}}})"

	def add(self, student: Student) -> bool:
		if type(student) is Student:
			self.students[student.id] = student
			return True
		return False

	def pop(self, id: int) -> bool:
		return bool(self.students.pop(id, False))

	def get(self, id: int = None, name: str = None) -> Student | None:
		if not id is None:
			return self.students.get(id)
		if not name is None:
			for student in self.students.values():
				if student.name == name:
					return student

def server(ip: str = "0.0.0.0", port: int = 5002):
	global_ns = {"__builtins__": {"print": print}, "Student": Student, "Students": Students, "students": Students()}
	def _send(result: str):
		try:
			csock.send(f"#{result}#".encode("utf-8"))
		except timeout:
			print(f"{ps1} Connection timed out")
		except error:
			print(f"{ps1} Connection error")
	def _handler(csock: socket):
		local_ns = {}
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
			print(f"{ps1} {cmd}")
			try:
				stdout = StringIO()
				with redirect_stdout(stdout), redirect_stderr(stdout):
					ret = eval(compile(cmd, "<string>", "single"), global_ns.copy(), local_ns)
				result = f"{stdout.getvalue()}{'' if ret is None else ret}"
			except Exception as e:
				result = str(e)
			finally:
				_send(result = result)
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
		if not cmd:
			continue
		if match(r"^exit$", cmd):
			sock.close()
			return 0
		if match(r"^help$", cmd):
			print("<command>    Execute single-line source on the server.")
			print("help         Show this help information")
			print("exit         Exit the client")
			continue
		try:
			sock.send(cmd.encode("utf-8"))
			res = sock.recv(1024)
			result = res.decode("utf-8")[1:-1]
			print(result, end="" if result[-1:] == "\n" else "\n")
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
		print(f"Students - Student Magagement Tool by Pairman")
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
