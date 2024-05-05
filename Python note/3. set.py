# set 集合

# 创建set：{} or set()
# notice: 由于set和 dict都是{}，所以如果创建empty set不能用{}
#         只使用{}创建的值为empty dict
set1 = {'Kevin', 'Angela', 'Zhuxun', 'Siming'}
set2 = set()

print(f'set1 type: {type(set1)}\
        \nset2 type: {type(set2)}\
        \nset1 content: {set1}\
        \nset2 content: {set2}')
        # set1 type: <class 'set'>
        # set2 type: <class 'set'>  
        # set1 content: {'Kevin', 'Siming', 'Zhuxun', 'Angela'}
        # set2 content: set()

set3 = {1 ,2 ,3 ,1} # 当有重复数据出现时，重复的数据将被舍弃
print(set3)

set2.add(1) # 添加 1 进入set
set2.add(2) # 添加 2 进入set
set2.add(2) # 添加 2 进入set，但set内已经有2存在，所以忽略该操作
print(set2) # {1, 2}

set2.update([1,2,3,4,5]) # 内部参数为list
set2.update((7,8))       # 参数也可以是tuple
print(set2)    # 将set或tuple内所有数据增加入set，并且忽略重复的数据。

print(set2.remove(6))  # 6不存在set内，报错
print(set2.remove(2))  # 2存在在set内，删除2，无返回值
print(set2)  # {1, 3, 4, 5, 7, 8} 
print(set2.discard(6)) # 6不存在set内，但不报错，无返回值
print(set2.discard(1)) # 1存在在set内，删除1，无返回值
print(set2)  # {3, 4, 5, 7, 8}
print(set2.pop())      # 没有参数，随机删除一个数据，并返回被删除的数据
print(set2)     

print('Kevin' in set1)       # set能判断value是否在set内
print('Angela' not in set1)
