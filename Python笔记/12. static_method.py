# static method 静态方法

class Dog(object):
    @staticmethod
    # 在这个function中，我们不需要使用任何类属性，只需要print一个内容
    # 这种就可以使用静态方法，让参数少一个self，在调用时不需要对class进行调用
    def info_print():
        print('这是一个狗类，用于创建狗的实例')


wangcai = Dog()
wangcai.info_print()

