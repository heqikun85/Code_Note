#for loop
"""
str1 = 'world' # str类型会以每个字符为一个单位进行for loop
list1 = [1, 2,  'this', 'is'] # list会根据每个内容为单位，按顺序
tuple1 = ('to', 'go', 'just', 'need') # tuple和list相同
set1 = {6 , 7, 'my', 'world'} # set也是以内容为单位，但是顺序是随机的
dict1 = {'name':'kevin', 'age': 37} # dict以键为单位，会根据顺序，但只会出现键名，不会出现键值

for i in str1:
    print(i)

for i in list1:
    print(i)

for i in tuple1:
    print(i)

for i in set1:
    print(i)

for i in dict1:
    print(i)
"""

#for loop break

list1 = ['kevin', 'angela', 'Evan', 'jessica', 'Xinyue', 'Sherry']
for i in list1:
    if i == 'Sherry': # if判断语句，检测到内容时使用break终止整个loop
        print('Sherry is here')
        break
    elif i == 'angela': # if判断语句，检测到内容时使用continue结束当前循环，但不终止loop
        print('I love angela')
        continue
    elif i == 'evan': # 区分大小写，词条判断将被忽略。
        print('evan no matter the character is upper letter')
    else:
        print (i)