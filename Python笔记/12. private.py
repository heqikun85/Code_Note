# private

class Prentice():
    def __init__(self):
        self.kongfu = '[独创煎饼果子配方]'
        # 设置money为private属性
        self.__money = 20000

    # 定义私有方法
    def __info_print(self):
        print(self.kongfu)
        print(self.__money)

    # 获取private属性值
    def get_money(self):
        return self.__money

    # 修改private属性值
    def set_money(self, salary):
        self.__money = salary

    def make_cake(self):
        # 私有属性只能在class内部被调用
        print(f'这是私有方法{self.__money}')


class Tusun(Prentice):
    pass


# 通过调用class中调用private属性的公用函数来对private属性进行操作
daqiu = Prentice()
daqiu.set_money(500)
print(daqiu.get_money())

# 因为父类中的get和set是public函数，所以子类也可以继承。
xiaoqiu = Tusun()
xiaoqiu.set_money(1000)
print(xiaoqiu.get_money())
