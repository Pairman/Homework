from geo_city_py.geo_city import *
from aqi_py.aqi_py import *
import json

def csv_parse(csv_filename, cursor = sqlite3.connect("geo_city_py/china_city_geo.db").cursor()):
	with open(csv_filename, "r", encoding = "utf-8") as csv_file:
		# Ignore the title line
		csv_file.readline()
		# Parse
		data_csv = dict()
		while True:
			# Read new row
			row = csv_file.readline().split(",")
			if len(row) == 1:
				break
			# Get province name
			province = latlon2province(float(row[11]), float(row[12]), cursor)[0:2]
			province = "黑龙江" if province == "黑龙" else "内蒙古" if province == "内蒙" else province
			# Append data to province
			if data_csv.get(province):
				data_csv[province].append(map(float, row[0:11]))
			else:
				data_csv[province] = [map(float, row[0:11])]
		# Calculate average AQI
		data_aqi = [{"name": province, "value": int(sum((aqi(*(tuple(entry)[0:6])) / len(entries)) for entry in entries) + 0.5)} for province, entries in data_csv.items()]
	return data_aqi

data = []
for d in range(101, 132):
	print("2013-01-" + str(d)[1:3], end = ": ")
	data.append(["2013-01-" + str(d)[1:3], csv_parse("csv/201301/CN-Reanalysis-daily-20130" + str(d) + "00.csv")])
	print("done.")
print(end = "output: ")
with open("csv/CN-AQI-daily-201301.js", "w") as json_output:
	json_output.write("var data = ")
with open("csv/CN-AQI-daily-201301.js", "a") as json_output:
	json.dump(data, json_output, indent = "  ")
print("done.")