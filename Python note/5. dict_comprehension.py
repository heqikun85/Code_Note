# dict comprehension 字典推导式
# 使用list创建dict
list1 = ['Google','Runoob', 'Taobao']
# 将列表中各字符串值为键，各字符串的长度为值，组成键值对
new_dict = {key:len(key) for key in list1}
print(new_dict)  # {'Google': 6, 'Runoob': 6, 'Taobao': 6}

#提供三个数字，以三个数字为键，三个数字的平方为值来创建字典：
dic = {x: x**2 for x in range(7) if x%2 == 0}
print(dic) # {0: 0, 2: 4, 4: 16, 6: 36}

# 合并两个list 为一个dict
list2 = [23,45,12]
new_dic = {list1[i]:list2[i] for i in range(len(list1))}
print(new_dic)  # {'Google': 23, 'Runoob': 45, 'Taobao': 12}

# 提取数据
counts = {'MBP': 268, 'HP': 125, 'DELL': 201, 'Lenovo': 199, 'acer': 99}
# 提取上述电脑数量大于等于200的字典数据
new_dic2 = {i:j for i,j in counts.items() if j > 200}
print(new_dic2) # {'MBP': 268, 'DELL': 201}
