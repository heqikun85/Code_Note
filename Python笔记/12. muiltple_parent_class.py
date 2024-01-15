# 多继承父类同时调用

# 1. first parent class
class Master(object):
    def __init__(self):
        self.kongfu = '[古法煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')


# 2. second parent class
class School(object):
    def __init__(self):
        self.kongfu = '[黑马煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')


class Prentice(School, Master):
    def __init__(self):
        self.kongfu = '[独创煎饼果子配方]'

    def make_cake(self):
        self.__init__()
        print(f'运用{self.kongfu}制作煎饼果子')

    # 同时调用多个父类中的同名属性和方法
    # 方法一：如果定义的类名修改，内部调用也要修改。
    # 将多个父类的初始化及方法在一个内部函数中同时定义。
    def make_old_cake(self):
        Master.__init__(self)
        Master.make_cake(self)
        School.__init__(self)
        School.make_cake(self)


daqiu = Prentice()

# 同时调用多个父类中的属性和方法，output如下
# 运用[古法煎饼果子配方]制作煎饼果子
# 运用[黑马煎饼果子配方]制作煎饼果子
daqiu.make_old_cake()
