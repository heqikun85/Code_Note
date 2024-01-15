# class method

# 1. 定义类
class Dog(object):
    __tooth = 10

    @classmethod
    def get_tooth(cls, tooth):
        cls.__tooth = tooth
        return cls.__tooth

    def get_tooths(self):
        return self.__tooth


wangcai = Dog()
# 这种情况下，class method 修改属性，会返回到类及实例对象
# 调用self时会显示修改后的值，说明实例对象的值被修改了
# 但cls调用的是class本身，所以class的值也被修改了。
print(wangcai.get_tooth(20))
print(wangcai.get_tooths())


# 1. 定义类
class Dog(object):
    __tooth = 10

    @classmethod
    def get_tooth(cls):
        return cls.__tooth

    def get_tooths(self, tooth):
        self.__tooth = tooth
        return self.__tooth


xiaohei = Dog()
# 这种情况下，self修改了实例对象的值。cls仍然显示的是class原本的值
print(xiaohei.get_tooths(20))
print(xiaohei.get_tooth())

# cls 调用的是类本身，self调用的是实例对象
# 在cls情况下更改，类本身也会更改，self则只更改实例对象
class Dog(object):
    tooth = 10

    @classmethod
    def get_tooth(cls, tooth):
        cls.tooth = tooth
        return cls.tooth

    def get_tooths(self, tooth):
        self.tooth = tooth
        return self.tooth

wangcai = Dog()

wangcai.get_tooth(20)
print(wangcai.tooth)
print(Dog.tooth)
wangcai.get_tooths(50)
print(wangcai.tooth)
print(Dog.tooth)