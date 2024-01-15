# 斐波那契数列

def fibonacci(num):
    if num == 0:
        return 0
    elif num == 1:
        return 1
    else:
        return fibonacci(num-1)+fibonacci(num-2)


f = fibonacci(2)
print(f)

# 黄金分隔比
import math

x = (math.sqrt(5)-1)/2
print('黄金分隔比例是 1：', x) # 黄金分隔比例是 1： 0.6180339887498949