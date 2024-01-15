# 公共操作2

str1 = 'Kevin'
str2 = " "
str3 = 'He'

list1 = [1, 2, 3]
list2 = [4, 5, 6]
list3 = ['kevin', 'angela']

t1 = (1, 2, 3)
t2 = (6, 5, 4)
t3 = ('kevin', 'angela')

dict1 = {'set': 2, 'set2': 3}
dict2 = {'list': 1, "list2": 4}

set1 = {1, 2, 3}
set2 = {4, 6, 5}
set3 = {'kevin', 'angela'}

# max(): 最大值
print(max(str1))    # output：v，v是这个str内数值最大的字符，根据ascii
print(max(list1))   # 返回3，3是list1内最大的数字
print(max(t1))      # 返回3，3是tuple1内最大的数字
print(max(dict1))   # 返回set2，通过key中说有字符相加，最大值为set2
print(max(dict1.values())) # 返回3，通过values函数，找到key value最大值
print(max(set1))    # 返回3，3是set1内最大的数字

# min(): 最小值
print(min(str1))    # output：K，K是这个str内数值最小的字符，根据ascii
print(min(list1))   # 返回1，1是list1内最小的数字
print(min(t1))      # 返回1，1是tuple1内最小的数字
print(min(dict1))   # 返回set，通过key中说有字符相加，最小值为set
print(min(dict1.values())) # 返回3，通过values函数，找到key value最小值
print(min(set1))    # 返回1，1是set1内最小的数字

t = range(0,9,3)
print(t)

for i in range(0,5,1):
    print(i)

for i in range(10,1,-1):
    print(i)

# enumerate()
for i in enumerate(str1, start= 2):
    print(i)
for i in enumerate(list1):
    print(i)
for i in enumerate(t1):
    print(i)
for i in enumerate(dict1):
    print(i)
for i in enumerate(set1):print(i)

print(set3.upper())
