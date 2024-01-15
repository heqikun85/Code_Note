# 类属性

# 1. 定义类，定义类属性
class Dog(object):
    tooth = 10    # 这个就是类属性，在class创建的variable

# 2. 创建对象
wangcai = Dog()

# 3. 访问类属性：类和对象
print(Dog.tooth)      # 直接通过类来访问类属性
print(wangcai.tooth)  # 通过对象来访问类属性

# 类属性的修改
# 通过实例对象来修改属性
wangcai.tooth = 15

# 类中的属性没有被修改，但实例对象的属性被修改了
# 说明当类创建了实例对象，实例对象实际上创建了一个新的内存空间
# 类仍然保持本身属性，而实例对象的属性可以有自己修改
print(Dog.tooth)
print(wangcai.tooth)

# 通过类修改属性
Dog.tooth = 20

# 类中的属性被修改了，但实例对象的属性没有被修改
# 说明类和实例，在第一次继承后使用了不同的内存空间。
# 两者修改不互相影响。但如果再次通过修改后的类创建对象，会使用新的属性值
print(Dog.tooth)
print(wangcai.tooth)