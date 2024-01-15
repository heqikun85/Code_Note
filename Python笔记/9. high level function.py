# 高阶函数

x = -100 + 5.72  # 返回-94.28

print(abs(x)) # 返回绝对值 94.28

print(round(x)) # 四舍五入，94

# 将函数作为参数传入另一个function
def add_num(a, b, f, d):
    return d(f(a)) + d(f(b))

result = add_num(-10.8, 2.3, abs, round)

print(result)