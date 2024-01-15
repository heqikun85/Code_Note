# parent class
# 单继承

# parent class, 参数中的object是指继承基类，也就是本身。
class A(object):
    def __init__(self):
        self.num = 1

    def info_print(self):
        print(self.num)


# 定义child class，参数中的 A 是指继承parent class A。
# 调用B class的时候可以使用A类的所有属性和方法。
class B(A):
    # 直接通过，不进行任何操作。
    pass

result = B()

# 验证结果成功，output：1，调用B class，通过B class的继承，使用了A class的方法。
result.info_print()

# 多继承

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


# 3. child class
# 在参数中加入两个class name，用逗号分隔
class Prentice(School, Master):
    pass

# 因为在测试时两个parent class使用了相同的属性名以及方法名
# 如果我们要通过child class来调用parent class的属性和方法时
# 默认使用第一个参数中的属性和方法，换句话说就是使用第一个parent class的属性和方法。
daqiu = Prentice()

daqiu.make_cake()  # 运用[黑马煎饼果子配方]制作煎饼果子



# 子类重写父类同名方法和属性

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


# 3. child class
# 在参数中加入两个class name，用逗号分隔
class Prentice(School, Master):
    def __init__(self):
        self.kongfu = '[独创煎饼果子配方]'

    def make_cake(self):
        print(f'运用{self.kongfu}制作煎饼果子')


# 如果子类有自己的属性和方法，并且和父类同名，则使用子类的属性和方法。
daqiu = Prentice()

daqiu.make_cake()  # 运用[独创煎饼果子配方]制作煎饼果子

# 这个代码可以列印处所有class的继承关系
# 第一个是子类本身，第二和第三个是继承的父类，第四个是继承的主类。
print(Prentice.__mro__) # (<class '__main__.Prentice'>, 
                        # <class '__main__.School'>, 
                        # <class '__main__.Master'>, 
                        # <class 'object'>)


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


# 3. child class
# 在参数中加入两个class name，用逗号分隔
class Prentice(School, Master):
    def __init__(self):
        self.kongfu = '[独创煎饼果子配方]'

    def make_cake(self):
        # 如果先调用了父类的属性和方法，父类属性回覆盖子类属性
        # 所以在调用属性前，先调用自己子类的初始化
        # 这个调用因为已经使用了self前缀，所以不需要在参数中加self
        self.__init__()
        print(f'运用{self.kongfu}制作煎饼果子')

    # 调用parent class（master / school）的属性和方法
    # 因为是继承来的数据，并且在class内部，所以需要使用self参数
    def make_master_cake(self):
        # 父类名.函数（）
        # 再次调用初始化的原因：这里要调用父类的同名属性和方法，
        # 属性在父类中的__init__初始化位置，所以需要再次调用__init__
        Master.__init__(self)
        Master.make_cake(self)

    def make_school_cake(self):
        School.__init__(self)
        School.make_cake(self)


# 如果子类有自己的属性和方法，并且和父类同名，则使用子类的属性和方法。
daqiu = Prentice()

daqiu.make_master_cake()    # 运用[古法煎饼果子配方]制作煎饼果子
daqiu.make_school_cake()    # 运用[黑马煎饼果子配方]制作煎饼果子
# 如果将子类中make_cake(self)函数中的self.__init__()这个取消的话
# 这行代码将会显示最后一次继承获得的父类属性和方法。
daqiu.make_cake()           # 运用[独创煎饼果子配方]制作煎饼果子