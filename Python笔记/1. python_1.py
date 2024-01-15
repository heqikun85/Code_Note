#this is comment
print("hello world")

"""
this is also comment
this mean mulitiple lines comments
"""
Num_Text1 = 10
Num_Text2 = 11.2
Num_Text3 = 0.5
Num_Text4 = 12.356

A = ["CHINA","USA","CHINESE"]
B = (10,20,30)
c = {"a", "b", "c"}
d = {'name': 'kevin', 'age': 23}
print("this is list", A)
print("this is tuple", B)
print("this is set", c)
print("this is dict", d)

numFloat = 10.5
numInt = 10
strName = 'this is a string'
numStr = '10'

# output 格式&变量定义类型
print('we print this content to show int %03d' %numInt)
print('here is float %.1f' %numFloat)
print('here is string %s' %(strName + ', THIS IS ADD STR'))
print("if we change the int to float %f " % (numInt + 12))
print('if change float to int %d' %numFloat)
print('all value show here str %s, numInt %d, numFloat %f' %(strName, numInt, numFloat))

print('if we change the str, it will be error %d' % strName)
#如果使用上面的代码，会显示TypeError: %d format: a number is required, not str
print('number string %d' %numStr)
#即便是这个str内是一个数字，也同样不可以运行。


print('here is all type value %s and %s and %s' %(numFloat, numStr, numInt))

print(f'here also can print int {numInt} and str {strName} and float {numFloat}')

print('hello \n world')
print('aaaaaaaaaaaa')
print('hello \t world')
print('aaaaaaaaaaaa')
print('hello\tworld')
print('\thello')

print('hello', end = ' ')
print('world')