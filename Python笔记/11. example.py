# 1. 定义类
class SweetPotato():
    # 初始化class属性
    def __init__(self):
        self.cook_time = 0
        self.cook_static = 'raw'
        self.cook_flavour = []
    
    # 定义说明
    def __str__(self):
        # 使用方法类似print
        return f'this potato cooked {self.cook_time} mins, static is {self.cook_static}, flavour has {self.cook_flavour}'
    
    def __del__(self):
        print('object has been delete')
    
    def cook(self, time):
        self.cook_time += time
        if 0 <= self.cook_time < 3:
            self.cook_static = 'raw'
        
        elif 3 <= self.cook_time < 5:
            self.cook_static = 'halfcooked'

        elif 5 <= self.cook_time < 8:
            self.cook_static = 'ripe'
        
        elif self.cook_time > 8:
            self.cook_static = 'overcooked'
            
    def add_flavour(self, flavour):
        # 添加调料
        self.cook_flavour.append(flavour)


# 调用类，创建对象
potato1 = SweetPotato()
print(potato1)

# 调用类中的cook函数
potato1.cook(2)
potato1.add_flavour('soy surce')
print(potato1)

# 第二次调用类中的cook函数
# 因为程序没有结束运行，所以第一次和第二次的调用是累加的
potato1.cook(2)
potato1.add_flavour('salt')
potato1.add_flavour('spicy')
print(potato1)