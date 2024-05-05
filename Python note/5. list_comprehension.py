# 推导式
'''
# 深度案例
names = ['Bob','Tom','alice','Jerry','Wendy','Smith']
new_names = [name.upper()for name in names if len(name)>3]
print(new_names)
'''
# 创建一个0-10的列表
# 1. while loop 实现
list1 = []     # 创建一个空列表
i = 0          # 创建while loop计数器
while i <= 10: # 限定while loop结束条件
    list1.append(i)  # 添加数据进入list1
    i += 1           # 计数器累加，防止无限循环
print(list1)

# for loop 实现
list2 = []
for i in range(11):
    list2.append(i)
print(list2)

# 3. 列表推导式实现
list3 = [i for i in range(11)]  # 创建表达式为临时变量 i，加入for循环遍历range(11)
print(list2)

# if 条件推导式
list3 = [i for i in range(11) if i % 2 == 0]
print(list3)

# 多个for循环列表推导式
# 创建列表为：[(1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]
list4 = [(i, j) for i in  range(1,3) for j in range(0,3) if i%2 == 0 if j%2 ==0]
print(list4)
