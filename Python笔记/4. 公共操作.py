# 公共操作

str1 = 'Kevin'
str2 = " "
str3 = 'He'

list1 = [1, 2, 3]
list2 = [4, 5, 6]

t1 = (1, 2, 3)
t2 = (6, 5, 4)

dict1 = {'set': 2, 'set2': 3}
dict2 = {'list': 1, "list2": 4}

set1 = {1, 2, 3}
set2 = {4, 6, 5}

# 合并&复制

print(str1 + str2 + str3) # output: Kevin He, 也可以这样给另一个变量赋值
print(list1 + list2) # output: [1, 2, 3, 4, 5, 6]
print(t1 + t2) # (1, 2, 3, 1, 2, 3)

# * 后面的数字代表复制多少次，但复制的内容不会更改变量本身
print(str1 * 2)  # output: KevinKevin
print(list2 * 2) # [4, 5, 6, 4, 5, 6]
print(t1 *2)     # (1, 2, 3, 1, 2, 3)
print(set1 + set2)

# del 目标 或 del(目标)
del str3
del list1
del list2[0]
del t1
#del t2[0]
del dict1
del dict2['list2']
del set1
print(str3)      # 数据undefined，报错
print(list1)     # 数据undefined，报错
print(list2)     # index 0的值为4，4被删除，output：[5, 6]
print(t1)        # 数据undefined，报错
print(t2)        # tuple不支持单个数据删除，报错
print(dict1)     # 数据undefined，报错
print(dict2)     # key为list2的键值对被删除，output：{'list': 1}
print(set1)      # 数据undefined，报错。set没有index，所以无法通过index删除指定数据   