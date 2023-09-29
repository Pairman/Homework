import json

data_input = None
with open("CityData.js", "r") as json_input:
	data_input = json.load(json_input)

data_dict = dict()
provinceNames = ["辽宁省", "黑龙江省", "山西省", "甘肃省", "贵州省", "北京市", "吉林省", "内蒙古自治区", "宁夏回族自治区", "福建省", "河北省", "湖北省", "陕西省", "江西省", "海南省", "江苏省", "河南省", "广西壮族自治区", "安徽省", "山东省", "四川省", "湖南省", "重庆市", "浙江省", "广东省", "云南省", "新疆维吾尔自治区", "青海省", "天津市", "上海市", "西藏自治区"]
for row in reversed(data_input[1:]):
	provinceName, cityName, city_confirmedCount, updateTime = row
	if not data_dict.get(updateTime):
		data_dict[updateTime] = dict.fromkeys(provinceNames, 0)
	data_dict[updateTime][provinceName] += city_confirmedCount

for i in range(1, len(tuple(data_dict.keys()))):
	updateTime_old, updateTime = tuple(data_dict.keys())[i - 1], tuple(data_dict.keys())[i]
	for provinceName in provinceNames:
		data_dict[updateTime][provinceName] += data_dict[updateTime_old][provinceName]

data = []
for updateTime, value in data_dict.items():
	row = [updateTime, []]
	for provinceName, province_confirmedCount in value.items():
		provinceName = provinceName[0:2]
		if provinceName == "内蒙":
			provinceName = "内蒙古"
		if provinceName == "黑龙":
			provinceName = "黑龙江"
		row[1].append({"name": provinceName, "value": province_confirmedCount})
	data.append(row)

with open("task2_sumup_byprovmap.js", "w") as json_output:
        json_output.write("var data = ")

with open("task2_sumup_byprovmap.js", "a") as json_output:
	json.dump(data, json_output, indent = "  ")