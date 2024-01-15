# super()调用父类方法

# 1. first parent class
class Master(object):
    def __init__(self):
        self.kongfu = '[古法煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')


# 2. second parent class
# 继承Master的属性和方法
class School(Master):
    def __init__(self):
        self.kongfu = '[黑马煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')
        # 通过super()调用Master 父类的属性和方法
        # super(School, self).__init__()
        # super(School, self).make_cake()


class Prentice(School):
    def __init__(self):
        self.kongfu = '[独创煎饼果子配方]'

    # 同时调用多个父类中的同名属性和方法
    # 方法二：super()
    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')
        # super(当前类名，self).函数()
        # 如果子类参数中有多个父类，则返回第一个父类的属性和方法
        # 所以这个方法继承多个父类没有用，单适用与多层嵌套继承
        # 可以通过让子类继承的父类，去继承另一个父类，来形成多层嵌套继承
        # 在上一层父类中同样加上super()，就可以做到同时继承多个父类的属性和方法。
        # super(Prentice, self).__init__()
        # super(Prentice, self).make_cake()

        # 无参数super()
        super().__init__()
        super().make_cake()


daqiu = Prentice()

#output：
#运用[独创煎饼果子配方]制作煎饼果子
#运用[黑马煎饼果子配方]制作煎饼果子
#运用[古法煎饼果子配方]制作煎饼果子
daqiu.make_cake()
