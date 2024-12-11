from socket import gaierror as _gaierror, getaddrinfo as _getaddrinfo

def resolve_ipaddr(host: str):
	"""Query information of a hostname.
	:host: The hostname.
	:return: Type name and resolved address of the hostname.
	"""
	try:
		info = _getaddrinfo(host, None)[0]
		af, addr = info[0].name, info[4][0]
	except _gaierror:
		af = addr = None
	finally:
		return af, addr