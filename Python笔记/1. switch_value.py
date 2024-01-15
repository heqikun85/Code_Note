#引用

# 交换变量
# 通过临时变量交换
from this import d


a = 10
b = 20 

c = a # c为临时变量，临时储存a的值
a = b # a 被b的值替换
b = c # b 被临时储存的c替换，

print(f'a is {a}, b is {b}') # a is 20, b is 10

# python允许另一种更简单的方法
# 直接用等号链接，两边将a 和 b 的顺序交换，让解释器知道我们需要互换变量
a, b = b, a

print(f'a is {a}, b is {b}') # a is 10, b is 20

#引用简介
d = 20
print(id(a))  # 2214675546640
print(id(b))  # 2214675546960
print(id(c))  # 2214675546640
print(id(d))  # 2214675546960

a = 10
b = [1 , 2 , 3]

print(f'a id: {id(a)}, b id: {id(b)}')

a = 11
b[1] = 5

print(f'a id: {id(a)}, b id: {id(b)}')