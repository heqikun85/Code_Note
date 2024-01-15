# 搬家具

class Furniture():
    # 初始化
    def __init__(self, name, area):
        self.name = name
        self.area = area

    # 定义说明
    def __str__(self):
        return f'this is {self.name}'

class Home():
    def __init__(self, address, area):
        self.address = address
        self.area = area
        self.free_area = area
        self.furniture = []

    def __str__(self):
        return f'the address is: {self.address}, area is {self.area}, free area is {self.free_area}, furniture has {self.furniture}'

    def add_furniture(self, item):
        """move furniture"""
        if self.free_area >= item.area:
            self.furniture.append(item.name)
            self.free_area -= item.area
        else:
            print("this furniture is too big")


# 通过furniture class 创建两个不同的对象
bed = Furniture('Queen Size Bed', 36)
sofa = Furniture('sofa', 20)
print(bed)
print(sofa)


home = Home('shanghai', 1000)
print(home)

# 调用home class的add 函数，把bed class作为参数传入
home.add_furniture(bed)
home.add_furniture(sofa)
print(home)