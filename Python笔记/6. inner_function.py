# inner function

# 定义第一个函数
def test1():
    print('this is test function')


def doFunction():
    print('here will call test1 function')
    test1()
    print('test1 function end')


doFunction()

# inner function example

# 定义一个函数，函数打印一条横线
def printLine():
    print('-' * 20)



# 打印多条横线
def multipleLine(num):
    i = 0
    while i < num:
        printLine()
        i += 1


multipleLine(3)


a = 10    # 定义一个变量
# 第一个函数不通过参数，直接在函数内调用a，并对a进行修改
# 结果是a可以被调用，并且在函数内数据被修改
def chan():
    global a 
    a = 12
    print('in chan function a is: %d' %a)   

# 第二个函数通过参数的形式调用a变量，同样可以修改
def chan2(x): 
    x = 13
    print('in chan2 function a is: %d' %x)

# 但在任何一种方式下，结束函数后a变量继续维持原本数据
# 函数内对global变量进行修改，只能在函数内显示，不会储存到全局。
chan()
print('after chan function a is %d' %a)
chan2(a)
print('after chan2 function a is %d' %a)
    
    
