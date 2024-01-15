# 多态 polymorphism

# 需求：警务人员与警犬共同工作。警犬分为两种：追击敌人和追查药品

# 分析步骤：
# 1. 定义父类，提供公共方法
# 2. 定义子类，子类重写父类方法
# 3. 创建对象，调用不同的功能，传入不同的对象。

# 定义Dog 父类
class Dog(object):
    def work(self):
        pass


# 定义ArmyDog 子类，继承Dog 父类
class ArmyDog(Dog):
    def work(self):
        print('追击敌人')


# 定义DurgDog 子类，继承Dog 父类
class DurgDog(Dog):
    def work(self):
        print('追查毒品')


# 定义Police 类
class Police(object):
    # 将一个对象作为参数传入
    def work_with_dog(self, dog):
        # 使用对象的方法
        dog.work()


# 用三个类创建对象
ad = ArmyDog()
dd = DurgDog()
pl = Police()

pl.work_with_dog(ad)   # 追击敌人
pl.work_with_dog(dd)   # 追查毒品