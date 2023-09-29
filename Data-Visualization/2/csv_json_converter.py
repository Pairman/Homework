import csv
import json

data = []
with open("daily-minimum-temperatures-in-me.csv", "r") as csv_input:
	reader = csv.reader(csv_input)
	for row in reader:
		data.append([row[0][0:4], row[0][5:10], row[1]])

with open("daily-minimum-temperatures-in-me.js", "w") as json_output:
        json_output.write("var data = ")

data[0] = ["Year", "Month and Day", "Temperature"]
with open("daily-minimum-temperatures-in-me.js", "a") as json_output:
	json.dump(data, json_output, indent = "  ")