# map

list1 = [1, 2, 3, 4]

def func(x):
    return x**2

x = map(func,list1)

print(x)       # return <map object at 0x0000027131A4ADD0>
print(list(x)) # return [1, 4, 9, 16]
