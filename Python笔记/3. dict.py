# 字典 dict
# dict的模式：{键值名：键值}
dict1 = {'Kevin': 37, 'Angela': 37, 'Siming': 18}
dict2 = {'Siming': 37, 'Zhuxun': 37, 'Sherry': 18}

# 并不是完全的复制，而是创建一个副本，内存地址相同
dict3 = dict2  # 如果任何一个被更改，其余2个也会被更改
print(dict1)
print(type(dict1))
print(dict1['Kevin']) # dict可以用键值名作为index来显示键值

dict2['Siming'] = 27 # Siming这个键值名原本的value 18，更改为27
print(dict2) # {'kevin': 37, 'angela': 37, 'siming': 27} 
print(dict3) # 因为dict2被更改，dict3是2的副本，所以也更改

# del function
del dict1['Siming'] # 将dict1从内存中删除，删除后dict1为undefined

# clear function
dict1.clear() # 清空dict，但不从内存中删除，保留一个空的dict
print(dict1)

print(dict1['Zhuxun']) #报错，没有这个key

# get function
print(dict1.get('Sherry', 100)) # sherry不是dict1的key，返回默认值100
print(dict1.get('Kevin'))       # key存在，返回key value
print(dict1.get('Sherry'))      # key不存在，没有默认值，返回 None

# keys function
print(dict1.keys())  # no arguments, 作用就是返回所有key名

# values function
print(dict1.values()) # no arguments, 返回所有key value

# items function
print(dict1.items()) # no arguments，返回成对的键值对，每个键值对以tuple的形式

# 遍历dict
for i in dict1:
    print(i)           # 遍历整个dict，只显示key，不限时key value
for i in dict1.keys(): # 通过keys函数，遍历所有key，和上面一样效果
    print(i)

for i in dict1:
    print(dict1[i])      # 通过遍历dict的key，将key作为参数，遍历所有key value
for i in dict1.values(): # 通过values函数，遍历所有key value，和上面一样作用
    print(i) 

for i in dict1.items(): # 遍历成对的键值对，每个键值对以tuple的形式存在
    print(i)

# 遍历键值对，并将键和键值分开
for key,value in dict1.items(): # for loop可以用两个value分别记录dict内成对的键和键值
    print(f'{key} = {value}')

# 拆包字典
dict1 = {'name': 'kevin', 'gender': 'male', 'age': 37}
dict2 = {'name': 'angela'}

a, b, c= dict1
print(f"a is: {a}, b is: {b}, c is: {c}")

print(f'a, b, c, could be dict index: {dict1[a]}, {dict1[b]}, {dict1[c]}')
# a is: name, b is: gender, c is: age
# a, b, c, could be dict index: kevin, male, 37