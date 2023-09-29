import json

data_input = None
with open("CityData.js", "r") as json_input:
	data_input = json.load(json_input)

data_dict = dict()

for row in data_input[1:]:
	provinceName, cityName, city_confirmedCount, updateTime = row
	if updateTime > "2020-04-01":
		continue
	if not data_dict.get(provinceName):
		data_dict[provinceName] = 0
	data_dict[provinceName] += city_confirmedCount

data = [["provinceName", "province_confirmedTotal"]]
for key, val in data_dict.items():
	data.append([key, val])

with open("task1_sumup_by41bar.js", "w") as json_output:
        json_output.write("var data = ")

with open("task1_sumup_by41bar.js", "a") as json_output:
	json.dump(data, json_output, indent = "  ")