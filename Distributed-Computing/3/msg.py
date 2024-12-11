#!/usr/bin/env python3

from matplotlib.pyplot import subplots, pause
from queue import Queue
from random import normalvariate
from threading import Thread
from time import sleep
from uuid import uuid4

n_devices = 3
n_history = 32

device_msg_queue = Queue(maxsize = n_devices * n_history)


def device_daemon():
	device_id = str(uuid4())
	while True:
		sleep(0.1)
		try:
			device_msg_queue.put((
				device_id,
				round(normalvariate(0, 1), 2)
			), block = False)
		except Exception:
			pass

analysis_msg_queue = Queue(maxsize = n_devices)

def analysis_daemon():
	data_dict = {}
	mean_dict = {}
	deviation_dict = {}
	maxmin_dict = {}
	while True:
		device_id, data = device_msg_queue.get()
		if not device_id in data_dict:
			data_dict[device_id] = [0] * n_history
		data_dict[device_id] = [*data_dict[device_id][1 : n_history], data]
		mean_dict[device_id] = sum(data_dict[device_id]) / n_history
		deviation_dict[device_id] = sum(
			(data - mean_dict[device_id]) ** 2
			for data in data_dict[device_id]
		) / (n_history - 1)
		maxmin = maxmin_dict.get(device_id, (0, 0))
		maxmin_dict[device_id] = (
			max(maxmin[0], data),
			min(maxmin[1], data)
		)
		try:
			analysis_msg_queue.put((
				device_id,
				data_dict[device_id],
				mean_dict[device_id],
				deviation_dict[device_id],
				maxmin_dict[device_id]
			), block = False)
		except Exception:
			pass

visualize_dict = {}
locals_dict = {}

def visualize_daemon():
	while True:
		device_id, data_list, mean, deviation, maxmin = analysis_msg_queue.get()
		if not device_id in visualize_dict:
			figure, axes = subplots()
			axes.set_xlim(0, n_history - 1)
			axes.set_ylim(-3, 3)
			line = axes.plot(range(n_history), data_list, "r-", lw = 2)[0]
			locals_dict[device_id] = (figure, axes, line)
		visualize_dict[device_id] = (data_list, mean, deviation, maxmin)
		for device_id in locals_dict:
			figure, axes, line = locals_dict[device_id]
			data_list, mean, deviation, maxmin = visualize_dict[device_id]
			axes.set_title(
				f"device_{device_id}\n"
				f"mean: {mean: .2f}, deviation: {deviation: .2f}\n"
				f"max: {maxmin[0]}, min: {maxmin[1]}"
			)
			line.set_ydata(data_list)
			figure.canvas.draw()
			figure.show()
			pause(0.01)

def main():
	Thread(target = analysis_daemon, daemon = True).start()
	for i in range(n_devices):
		Thread(target = device_daemon, daemon = True).start()
	visualize_daemon()

if __name__ == "__main__":
	main()