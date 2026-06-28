import matplotlib.pyplot as plt
# 解决图表中文乱码
plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False

# 读取txt空气质量数据
def read_air_file():
    raw_data = []
    f = open("air.txt", "r", encoding="utf-8")
    lines = f.readlines()
    f.close()
    for line in lines:
        line = line.strip()
        if line == "":
            continue
        data = line.split(",")
        raw_data.append(data)
    return raw_data

# 清洗无效脏数据
def clean_data(raw_list):
    clean_list = []
    for item in raw_list:
        if len(item) != 2:
            continue
        city, pm = item[0], item[1]
        if pm.isdigit():
            clean_list.append([city, int(pm)])
    return clean_list

# 计算各城市PM2.5平均值
def get_avg(clean_list):
    city_dict = {}
    for city, num in clean_list:
        if city not in city_dict:
            city_dict[city] = []
        city_dict[city].append(num)
    avg_dic = {}
    for city, nums in city_dict.items():
        avg_dic[city] = sum(nums) / len(nums)
    return avg_dic

# 绘制柱状对比图
def draw_chart(avg_data):
    cities = list(avg_data.keys())
    pm_values = list(avg_data.values())
    plt.bar(cities, pm_values, color="steelblue")
    plt.title("各城市PM2.5平均浓度对比")
    plt.xlabel("城市")
    plt.ylabel("PM2.5浓度")
    plt.show()

# 程序入口，自动执行全部流程
if __name__ == "__main__":
    data1 = read_air_file()
    data2 = clean_data(data1)
    avg_result = get_avg(data2)
    draw_chart(avg_result)