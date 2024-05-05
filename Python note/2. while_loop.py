#while loop

j = 1
# while + 条件（条件可以用and链接，连接的不同条件可以用括号以便阅读）
while j <= 3:
    i = 1 # while 计数器
    while i <= 5: 
        if i == 4: #内嵌if判断条件
            print('吃饱了，不吃了')
            break # 终止while loop
        elif i == 2: 
            print(f'第{i}个苹果有虫子，不吃了')
            i += 1 # 计数器增加，防止无限循环
            continue # 终止本次循环，不运行下一条命令，但不会退出while loop
        print(f'吃了{i}个苹果') # 退出if判断语句
        i += 1 # 计数器，这个计数器和if判断内的计数器共享数据。
    j += 1
    print(f'第{j}天')


#矩形星号
i = 1
while i <= 5:
    j = 1
    while j <= 5:
        print("*", end = '')
        j += 1
    print('')
    i += 1


#递增星号
i = 1
while i <= 5:
    j = 1
    while j <= i:
        print('*',end = '')
        j += 1
    print('')
    i += 1

#99乘法表
i = 1
while i <= 9:
    j = 1
    while j <= i:
        print(f'{i}*{j}={(i*j)}',end = '\t')
        j += 1
    print('')
    i += 1

#while else 语法
i = 1
while i <= 5:
    if i == 2:
        print('我不想运行了')
        i += 1
        break
    print(i)
    i += 1
    j = 1
else:
    j = 0
    print('正常结束while loop')

if j != 0 :
    print('老子没有运行完')
else:
    print('老子正常运行完了')