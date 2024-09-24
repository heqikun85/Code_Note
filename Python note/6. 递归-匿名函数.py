
# 递归函数
def test (n: int) -> int:
    if n == 1:
        return 1
    return n * test(n-1)
    
print(test(5))


# 匿名函数
# 如果一个函数有一个返回值，并且只有一句代码，可以使用 lambda简化。
fn = lambda x, y : x + y
print(fn(3,4))

# 注意: 1. lambda表达式的参数可有可无;
#       2. 函数的参数在lambda表达式中完全适用。
#       3. lambda表达式能接收任何数量的参数但只能返回一个表达式的值
#       4. 直接打印lambda表达式，输出的是此lambda的内存地址

# lambda函数的主要作用是作为c++/java的二元判断法的
fn1 = lambda a, b : a if a > b else b
print(fn1(5,10))
# 上面这段就是，如果a比b大则返回a，否则返回b