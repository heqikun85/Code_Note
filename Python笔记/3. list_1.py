#list

name_list = ['Tom', 'Lily', 'Rose'] # 定义一个list，变量名为name_list

print(name_list)    # output: 整个list
print(name_list[0]) # output: Tom // 通过index调用单个数据

print(name_list.index('tom', 3,5)) # 结束位置不包括在查找范围内，
                                   #并且如果没有匹配数据会导致程序终止。
print(name_list.count('Tom')) # output: 2, 说明函数区分大小写
print(len(name_list))         # output: 5, 

print('Rose' in name_list)    #true, Rose in the list
print('Tom' not in name_list) #false, Tom in the list

userName = input('请输入你的名字: ') # 用户输入
if userName in name_list:         # 判断用户输入是否已存在list中
    print('the user name has been used')
else:
    print('hello new user')

name_list2 = ['Tom', 'Rose', 'Lily']
name_list3 = ['Tom', 'Rose', 'Lily']


name = 'Kevin'
name1 = ['wenhui', 'angela']
name2 = ('sherry', 'xiaoye')
name_list.append(name)  # str格式作为新的数据加入队尾
name_list.append(name1) # list格式作为sublist被加入队尾
name_list.append(name2) # tuple格式作为subtuple被加入队尾
name_list.append(23)    # num格式作为新的num数据加入队尾
print(name_list)
name_list3.extend(name)  # str格式被分拆成单个char按顺序加入队尾
name_list3.extend(name1) # list格式中所有数据按顺序作为新数据加入队尾
name_list3.extend(name2) # tuple格式中所有数据按顺序作为新数据加入队尾
print(name_list3)        # 不可加入num格式数据
name_list2.insert(1, name)  # str格式作为新数据加入index 1的位置
name_list2.insert(2, name1) # list格式作为sublist被添加到index 2
name_list2.insert(3, name2) # tuple格式作为subtuple被添加到index 3
name_list2.insert(2, 23)    # num格式作为新数据加入index 2
print(name_list2)

del name_list3
print(name_list3)  # 显示name_list3 undefined，将整个list从内存中删除
del name_list2[0]
print(name_list2)   # Tom 被删除
print(name_list3.pop())  # 返回被删除的数据，不定义index的情况下，默认删除最后一个
print(name_list3)        # output list中剩余数据
print(name_list3.pop(0)) # 括号中可以指定index
print(name_list3)        # index 0的Tom被删除
print(name_list3.remove('Tom')) # 指定删除数据，返回none'''
name_list2.remove()
print(name_list2)
print(name_list3)               # Tom被删除
print(name_list.clear())  # 删除整个list，返回none
print(name_list)          # 但list仍然存在，显示为一个空的list