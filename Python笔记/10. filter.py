# filter

def func(a):
    return a % 2 == 0

print(func(3)) # 返回的是true/false

list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 接受true/false作为参数，来判断list1内每个元素是否符合条件，并返回新的迭代器
x =  filter(func, list1) 

print(x)       # 返回迭代器，<filter object at 0x000001762171BC70>
print(list(x)) # [2, 4, 6, 8, 10]

