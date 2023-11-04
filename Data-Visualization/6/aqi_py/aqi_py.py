# CN IAQI and AQI (24h)
iaqi_p = [0,  50, 100, 150, 200,  300,  400,  500, 99999999]
b_so2  = [0,  50, 150, 475, 800, 1600, 2100, 2620, 99999999]
b_no2  = [0,  40,  80, 180, 280,  565,  750,  940, 99999999]
b_pm10 = [0,  50, 150, 250, 350,  420,  500,  600, 99999999]
b_co   = [0,   2,   4,  14,  24,   36,   48,   60, 99999999]
b_o3   = [0, 160, 200, 300, 400,  800, 1000, 1200, 99999999]
b_pm25 = [0,  35,  75, 115, 150,  250,  350,  500, 99999999]

def iaqi_so2(b_p):
	i, bp = 0, b_so2
	while i < len(bp) - 1:
		if bp[i] <= b_p < bp[i + 1]:
			break
		i += 1
	if i == 7:
		return iaqi_p[7]
	return int((iaqi_p[i + 1] - iaqi_p[i]) / (bp[i + 1] - bp[i]) * (b_p - bp[i]) + iaqi_p[i])

def iaqi_no2(b_p):
	i, bp = 0, b_no2
	while i < len(bp) - 1:
		if bp[i] <= b_p < bp[i + 1]:
			break
		i += 1
	if i == 7:
		return iaqi_p[7]
	return int((iaqi_p[i + 1] - iaqi_p[i]) / (bp[i + 1] - bp[i]) * (b_p - bp[i]) + iaqi_p[i])

def iaqi_pm10(b_p):
	i, bp = 0, b_pm10
	while i < len(bp) - 1:
		if bp[i] <= b_p < bp[i + 1]:
			break
		i += 1
	if i == 7:
		return iaqi_p[7]
	return int((iaqi_p[i + 1] - iaqi_p[i]) / (bp[i + 1] - bp[i]) * (b_p - bp[i]) + iaqi_p[i])

def iaqi_co(b_p):
	i, bp = 0, b_co
	while i < len(bp) - 1:
		if bp[i] <= b_p < bp[i + 1]:
			break
		i += 1
	if i == 7:
		return iaqi_p[7]
	return int((iaqi_p[i + 1] - iaqi_p[i]) / (bp[i + 1] - bp[i]) * (b_p - bp[i]) + iaqi_p[i])

def iaqi_o3(b_p):
	i, bp = 0, b_o3
	while i < len(bp) - 1:
		if bp[i] <= b_p < bp[i + 1]:
			break
		i += 1
	if i == 7:
		return iaqi_p[7]
	return int((iaqi_p[i + 1] - iaqi_p[i]) / (bp[i + 1] - bp[i]) * (b_p - bp[i]) + iaqi_p[i])

def iaqi_pm25(b_p):
	i, bp = 0, b_pm25
	while i < len(bp) - 1:
		if bp[i] <= b_p < bp[i + 1]:
			break
		i += 1
	if i == 7:
		return iaqi_p[7]
	return int((iaqi_p[i + 1] - iaqi_p[i]) / (bp[i + 1] - bp[i]) * (b_p - bp[i]) + iaqi_p[i])

def aqi(b_p_pm25, b_p_pm10, b_p_so2, b_p_no2, b_p_co, b_p_o3):
	return max(iaqi_so2(b_p_so2), iaqi_no2(b_p_no2), iaqi_pm10(b_p_pm10), iaqi_co(b_p_co), iaqi_o3(b_p_o3), iaqi_pm25(b_p_pm25))