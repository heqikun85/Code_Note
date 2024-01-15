# 递归 recursion

# sum_numbers被调用了3次，第一次调用时，if判断错误，运行下面的return
# num = 3， 然后加上再次调用sum_numbers()，但这时参数为num-1
# 也就是参数为2，判断仍然失败。在return处为2+sum_numbers函数
# 参数再次减1后为1，if判断成功，返回1.
# 所以此代码在进入2层嵌套后等于，return 3 + （2 + 1）
def sum_numbers(num):
    # 出口，如果没有出口，会因超出最大递归深度而报错
    if num == 1:
        return 1
    return num + sum_numbers(num - 1)

print(sum_numbers(3))

# lambda表达式，也叫匿名函数
# x 被赋值的是lambda的内存地址，并不是一个值，所以X等同于一个function而不是一个值
x = lambda num1,num2: num1+num2

print(x(10,12))

# lambda参数形式和函数参数形式一样
x1 = lambda: 100 # 无参数，return 100
x2 = lambda a, b, c = 100: a + b + c # 默认参数，可指定参数，但必须按照顺序规则
x3 = lambda a = 110, b, c: a+b+c  # 第一个参数被定义，所以之后的也必须被定义
x4 = lambda *args: args # 以tuple的形式传入不定长的可变参数
x5 = lambda **kwargs : kwargs # 以dict的形式传入成对的不定长可变参数

print(x2(10, 20))      # 使用默认参数
print(x2(10, 20, 30))  # 不使用默认参数
print(x4(10,20,30))    # 返回tuple形式 (10, 20, 30)
print(x5(name='kevin',location='shanghai')) # 作为参数的dict key不需要引号，并且用等号链接key value

# 带判断的lambda
fn1 = lambda a, b: a if a > b else b # 如果a大于b返回a，否则返回b

student = [{'name':'Tom', 'age': 29}, {'name':'Kevin', 'age': 37}, {'name':'Sherry', 'age':23}]

# sort函数是list用来排序的，通过lambda函数遍历所有dict的name，以此作为list的内容来排序
student.sort(key = lambda x : x['name']) 
print(student)
# 不能直接使用reverse，因为dict并不支持sort函数，我们要通过lambda函数将student转换为纯list才能使用sort函数。
student.sort(key = lambda x: x['name'], reverse = True)
print(student)