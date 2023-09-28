import csv
import json

data = [["Year", "Month and Day", "Temperature"]]

with open("daily-minimum-temperatures-in-me.csv", "r") as csv_input:
	reader = csv.reader(csv_input)
	for row in reader:
		data.append([row[0][0:4], row[0][5:10], row[1]])

with open("daily-minimum-temperatures-in-me.js", "w") as json_output:
	json.dump(data, json_output, indent = "  ")