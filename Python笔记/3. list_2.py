# list 修改

name_list = ['Tom', 'Jerry', 'Rose', 'Lily', 'Kim']
name_list[2] = 'Kevin'
print(name_list)  # 原本index 2的Rose被更改为Kevin

name_list.reverse() # 无返回值
print(name_list)    # list的顺序被颠倒
name_list.sort()    # 无返回值
print(name_list)    # 根据ascii表来排序，排序默认为顺序
name_list.sort(reverse = True)
print(name_list)   # 在sort函数中加入参数reverse = True，则变为降序排列

# list 复制
name_list = ['Tom', 'Jerry', 'Rose', 'Lily', 'Kim']
# copy name_list去到name_list1，并且是创建一个新的list而非创建一个副本
name_list1 = name_list.copy() 
#print后我们可以看到，两个list的address是不同的
print(f'name list 1: {name_list1}\nname_list1 address is: {id(name_list1)}\
    \nname_list address is: {id(name_list)}')


# list 遍历
name_list =  ['Tom', 'Jerry', 'Rose', 'Lily', 'Kim']

i = 0 
while i < len(name_list):
    print(name_list[i])
    i += 1

for i in name_list:
    print(i)

# list 嵌套
name_list = [['kevin','angela'],['siming','zhuxun'],['gorden','nvpeng']]

print(name_list[0][1]) # 第一个index 0 代表第一个内部list
                       # 第二个index 1 代表第一个list内的第二个值
                       # output：angela
for i in range(len(name_list)): # range函数，参数中是范围，9的话返回0-8
    for j in name_list[i]:      # for 嵌套函数要注意，他的参数并不是index，而是value
        print(j, end = '\n\n')

for i in range(len(name_list)):        #直接通过两个range获取遍历index也可以实现遍历3dlist
    for j in range(len(name_list[i])):
        print(name_list[i][j])

# 综合应用： 8位老师随机分配到3个办公室
import random

office = [[],[],[]]  # 创建嵌套列表
teacher = ['Kevin', 'Angela', 'SiMing', 'ZhuXun', 'YiHuang', "Evan", 'Sherry', 'WenHui']

for i in range(len(teacher)):             # 通过range函数循环teacher长度的次数
    office_num = random.randint(0,2)      # 创建随机数 
    while len(office[office_num]) >= 3:   # while loop 保证办公室人数均衡
        office_num = random.randint(0,2)  
    office[office_num].append(teacher[i]) # 将老师分配到办公室
print(office)



