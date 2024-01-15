# set comprehension 集合推导式

# 创建集合
# 创建一个集合, 数据为下方list的平方
list1 = [1, 1, 2]
set1 = {i**2 for i in list1}
print(set1) # 因为set有去重功能，所以重复的1被舍去

# tuple comprehension 元祖推导式
a = (i for i in range(10) if i%2 == 0)
print(a) # <generator object <genexpr> at 0x10a3c9b60> 返回了一个构建地址
b = tuple(a) # 将构建地址内的数据转换成tuple
print(b)     # (0, 2, 4, 6, 8)