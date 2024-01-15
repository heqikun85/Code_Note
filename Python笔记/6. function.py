# function 函数

# 定义函数
def printWord(i, j):
    print(i + ' ' + j)

str1 = 'Kevin'
str2 = 'He'

# 调用函数，并将两个str作为arguments传入函数
printWord(str1, str2)

# function return value 函数返回值

#定义函数
def getList(i):
    new_list = [key for key in i]
    return new_list

list1 = ['you', 'are', 'best']
a = getList(list1)
print(a)

# function 简单的应用
# 轻量级计算机

def calcul(x, y, z):
    if z == '+':
        # 因为输入都是str格式，所以需要转换格式
        return (int(x) + int(y))
    elif z == '-':
        return (int(x) - int(y))
    elif z == '*':
        return (int(x) * int(y))
    else:
        return (int(x) / int(y))

x = input('enter first num: ')
y = input('enter second num: ')
z = input('enter calcul way: ')

result = calcul(x,y,z)
print(result)