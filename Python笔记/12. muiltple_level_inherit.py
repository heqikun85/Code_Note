# 多层继承

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
class Prentice(School, Master):
    def __init__(self):
        self.kongfu = '[独创煎饼果子配方]'

    def make_cake(self):
        self.__init__()
        print(f'运用{self.kongfu}制作煎饼果子')

    def make_master_cake(self):
        Master.__init__(self)
        Master.make_cake(self)

    def make_school_cake(self):
        School.__init__(self)
        School.make_cake(self)


# 创建二级子类
# 4. grand_child class
class Grand_child(Prentice):
    pass

tusun = Grand_child()

tusun.make_master_cake() # 调用master class的属性和方法
tusun.make_school_cake() # 调用school class的属性和方法
tusun.make_cake()        # 调用Prentice class的属性和方法
# 返回一个tuple类型的继承列表
# (<class '__main__.Grand_child'>, 
#  <class '__main__.Prentice'>, 
#  <class '__main__.School'>, 
#  <class '__main__.Master'>, 
#  <class 'object'>)
print(Grand_child.__mro__)