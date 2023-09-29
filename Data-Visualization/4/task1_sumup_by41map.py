import json

data_input = None
with open("CityData.js", "r") as json_input:
	data_input = json.load(json_input)

data_dict = dict()

for row in data_input[1:]:
	provinceName, cityName, city_confirmedCount, updateTime = row
	if updateTime > "2020-04-01":
		continue
	if not data_dict.get(provinceName[0:2]):
		data_dict[provinceName[0:2]] = 0
	data_dict[provinceName[0:2]] += city_confirmedCount

data_dict["内蒙古"] = data_dict["内蒙"]
data_dict["黑龙江"] = data_dict["黑龙"]

data = []
for key, val in data_dict.items():
	data.append({"name": key, "value": val})

with open("task1_sumup_by41map.js", "w") as json_output:
        json_output.write("var data = ")

with open("task1_sumup_by41map.js", "a") as json_output:
	json.dump(data, json_output, indent = "  ")