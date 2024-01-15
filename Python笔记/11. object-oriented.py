# 面向对象

# 需求：洗衣机。功能：洗衣服
# 1. 定义洗衣机类
class Washer():
    def wash(self):
        print('洗衣服')
        print(self)


# 2. 创建对象
# 对象名 = 类名()
haier = Washer()


# 3. 验证成果
# 打印对象，返回的是对象的内存地址
print(haier)  # <__main__.Washer object at 0x0000014C83A3AD40>

# 使用Wash功能 -- 对象名.wash
# 运行class Washer内的wash函数 
haier.wash() # 洗衣服


# Class object value
class TestClass():
    # class 内的属性变量
    str1 = str
    list1 = []
    tuple1 = ()

    # class 内print功能function
    # 通过self能把class内的属性作为参数传入内部function
    def print_info(self):
        print(f'this is str {self.str1}')
        print(f'this is list {self.list1}')
        print(f'this is tuple {self.tuple1}')

# 用class创建对象
test = TestClass()

# 通过对象将class内的属性变量赋值，也就是从外部添加属性进入class
test.str1 = 'I love you'
test.list1 = [1,2,3,4,5]
test.tuple1 = (0,9,8,7,6)

# 外部打印class内的属性
print(test.str1)   # I love you
print(test.list1)  # [1, 2, 3, 4, 5]
print(test.tuple1) # (0, 9, 8, 7, 6)

# 通过class内的print_info function来打印内容
test.print_info()  # this is str I love you 
                   # this is list [1, 2, 3, 4, 5]
                   # this is tuple (0, 9, 8, 7, 6)

