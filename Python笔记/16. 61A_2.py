# 嵌套 lambda 和 function的参数关系

make_adder = lambda x: lambda y: x + y

one = input('enter first num: ')
# 在这种嵌套情况下，我们可以想成，make_adder()已有了参数
# adder实际上赋值了make_adder()内部的另一个函数
adder = make_adder(one)
two = input('enter second num: ')
# 当调用adder()时，实际上这个参数，是进入了y这个参数
print(adder(two))

# 案例二
a = 1
# 实际上有2个参数，x()的参数b，y()参数d
def x(b):
    c = 3
    def y(d):
        e = 5
        return b + d + e
    return y

# z被赋值为x(a+1), x()参数b被赋值为2
z = x(a + 1)
f = 6
# 调用z时使用参数，y()参数d被赋值为6
print(z(6))

# round()
print(round(1.234567,3))  # 保留3位小数，1.235



def special_case():
    x = 10
    if x > 0:
        x += 2
    elif x < 13:
        x += 3
    elif x % 2 == 1:
        x += 4
    return x

def just_in_case():
    x = 10
    if x > 0:
        x += 2
    if x < 13:
        x += 3
    if x % 2 == 1:
        x += 4
    return x

def case_in_point():
    x = 10
    if x > 0:
        return x + 2
    if x < 13:
        return x + 3
    if x % 2 == 1:
        return x + 4
    return x

print(special_case())  # if判断后跳过elif判断 12
print(just_in_case())  # 不跳过任何一个if判断 19
print(case_in_point()) # 第一个if判断后return了，之后的代码不运行 12


def happy(text):
	return "☺" + text + "☺"
	    
def sad(text):
	return "☹" + text + "☹"
	
def make_texter(emoji):
    def texter(text):
	    return emoji + text + emoji
    return texter    

def composer(f, g):
	def composed(x):
	    return f(g(x))
    return composed

# 1. f = happy(), g = make_texter("☃︎")
# 2. 外部再加一个括号，作为内嵌函数的参数，snow day! = composer()的参数 x
# g(x) = ☃︎snow day!☃︎, ☃︎是父级参数emoji，snow day!是本地调用参数text
# f(g(x)), 将整个return的 ☃︎snow day!☃︎，作为参数
# return最终结果： ☺☃︎snow day!☃︎☺
print(composer(happy, make_texter("☃︎"))('snow day!'))