# reduce

import functools

list1 = [1, 2, 3, 4, 5]

def func(a,b):
    return a + b

result = functools.reduce(func,list1)

print(result)