# 魔法方法

class Washer(): # class内部的参数不需要在定义class时写在class参数中
    # 定义_init_, 通过参数来添加实例属性
    def __init__(self, width, height):
        #  通过参数来添加实例属性
        self.width = width
        self.height = height
    
    def __str__(self):
        return '这是海尔洗衣机的说明书'
    
    # 在对象运行完成后，对象会被删除。
    # 当对象被删除时自动调用__del__函数
    def __del__(self):
        print('对象已经删除')

    def print_info(self):
        # class里调用实例属性
        print(f'width is: {self.width}')
        print(f'height is: {self.height}')


haier = Washer(10, 20)

# width is: 10
# height is: 20
haier.print_info()

# 因为有了__str__()，所以不返回内存地址，返回str函数返回的说明文字
print(haier) # output: 这是海尔洗衣机的说明书

