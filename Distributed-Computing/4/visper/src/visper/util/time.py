from datetime import datetime as _datetime
from time import time as _time

def time_ms():
	"""Get millisecond-level timestamp.
	:return: Timestamp.
	"""
	return int(_time() * 1000)

def parse_time_ms(ms: int):
	"""Parse millisecond-level timestamp.
	:param ms: The timestamp.
	:return: ``datetime.datetime`` object.
	"""
	return _datetime.fromtimestamp(timestamp = ms / 1000)