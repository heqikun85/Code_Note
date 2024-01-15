# 缺省参数/默认参数
# 定义函数时加上某个参数的值，就为默认值
'''def test(name, gender, age = 20):
    print(f'name: {name}, gender is: {gender}, age is: {age}')

test('angela', 'female', ) # 省略最后一个参数的情况下，使用参数的默认值
test('kevin', 'male', 37)  # 不省略参数的情况下，使用写入值

output: 
name: angela, gender is: female, age is: 20
name: kevin, gender is: male, age is: 37

# 和关键字参数相同，需要遵从一旦使用默认参数，之后的参数都要使用默认参数
'''
# 不定长参数/可变参数
def test(*argu):
    print(type(argu)) # <class 'tuple'>
    print(f'name is: {argu[0]}, age is: {argu[1]}') #name is: tom, age is: 18

test('tom', 18)
#其实可以理解为将一个tuple作为参数传入

# 不定长关键字参数
def test1(**kwargs):
    print(kwargs)

test1(name = 'Tom', age = 18, id = 110) # {'name': 'Tom', 'age': 18, 'id': 110}

