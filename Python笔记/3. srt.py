# str切片

str1 = '0123456789'

 # index从0开始，index 2 为开始位置，index 5 为结束位置
 # 结束位置不包括在切片范围内。
 # 第三个参数步长为选取间隔，所以最小为1，如果为0则会报错
 # 句话说，开始位置为index 2， 步长为3，下一个选取的对象为 index 2+3
 # 也就是5，再下一个为index 5+3，8 
print(str1[-4:-1])

str2 = 'he\'s my father'
str3 = "he's my father"
str4 = 'this book name is "I love you"'
str5 = "this book name is \" I love you\" "

print(str5)

str6 = "12345"

print(str6)
print('this is str %s' %str6)
print(f'this is str {str6}')

myStr = '    this is my is world    '

data = myStr.rfind('my', 2, 10)
#data2 = myStr.index('my', 2, 9)
data3 = myStr.count('is')

data4 = myStr.replace(' is ', ' at ')
print(data)
print(data4)

a = 10
b = 10
c = d = 20
e = [1,2,3,4]
print(f'a is {id(a)}\nb is {id(b)}\nc is {id(c)}\nd is {id(d)}\ne is {id(e)}')
a = 15
e.append(5)
print(f'a is {id(a)}\nb is {id(b)}\nc is {id(c)}\nd is {id(d)}\ne is {id(e)}')

list1 = myStr.split('is')
print(list1)

myList = ['this', 'is', 'my', 'world']
data = ' '
new_data = data.join(myList)
print(new_data)
data2 = 'a'
new_data2 = data2.join(myList)

data1 = new_data.capitalize()
data2 = new_data.title()
data3 = new_data.lower()
data4 = new_data.upper()
print(data1) # This is my world
print(data2) # This Is My World  
print(data3) # this is my world
print(data4) # THIS IS MY WORLD

print(myStr.lstrip())
print(myStr.rstrip())
print(myStr.strip())

print(new_data.ljust(20, '*')) # this is my world****
print(new_data.rjust(20, '*')) # ****this is my world
print(new_data.center(20, '*')) # **this is my world**

print(new_data.startswith('this', 0, 15))  # True, this是开头
print(new_data.startswith('is', 5, 15)) # True, 起点是5，i的index是5
print(new_data.startswith('is', 4, 15)) # False, 起点是4， index为4的是空格
print(new_data.endswith('my', 5, 10)) # True, my的index分别是8，9
print(new_data.endswith('my',5,9)) # False，因为结束点不计算在截取范围内，所以我们要在结束点+1


print(new_data.isalpha()) # False空格不算字母
print(new_data2.isalpha()) # True，更改后全是字母判断为True
print(str1.isdigit())      # True，str1全是数字
print(new_data.isdigit())  # False
print(new_data.isalnum()) # False, 空格不算字母或数字
print(new_data2.isalnum()) # True
print(new_data.isspace())  # False, 有字母和数字
