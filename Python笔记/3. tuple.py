# 元祖
tuple1 = ('kevin', 'angela', 'siming', 'zhuxun')
print(tuple1)
print(type(tuple1))

# 在定义tuple时，如果只有单个数据，必须在后面加上逗号，不加的话会以数据本身类型储存
tuple2 = (10,)
tuple3 = (20)
print(type(tuple2)) # <class 'tuple'>
print(type(tuple3)) # <class 'int'>

dict1 = {'kevin': 37, 'angela': 37}
print(len(dict1))  # 长度为2

print(range(len(tuple1))) # range(0, 4)
print(range(len(dict1)))  # range(0, 2)