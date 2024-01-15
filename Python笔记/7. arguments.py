# 参数 argument

# 参数位置
def test1(name, age, gender):
    # 在函数内使用参数时，位置没有影响，而是由参数的名称来决定
    print(f'student name is {name}, he/she is {age}, he/she is {gender}')
    print(f'gender: {gender}\nname: {name}\nage: {age}')


# 但在调用函数时，传入的参数必须按照函数定义时的顺序来
test1('kevin', 37, 'male')
# 如果不按顺序，函数内数据就会出错
test1(37, 'male', 'kevin')


output: 
# first call
student name is kevin, he/she is 37, he/she is male
gender: male  name: kevin  age: 37


# second call
student name is 37, he/she is male, he/she is kevin
gender: kevin  name: 37  age: male

# 关键字参数

# 没有使用关键字参数的参数，仍然要遵守位置参数的规则
# 并且必须在关键字参数之前，比如这个，第二个参数就显示错误
test1(age = 37, 'kevin', gender= 'male')

# 由于name是关键字参数，又必须在位置参数之后，所以下面这段代码出现错误
# 因为gender未指定关键字，但他在的位置是name，所以程序收到2个name的参数
test1('male', name = 'kevin', age = 37)

# 没有使用关键字参数的参数，要遵守位置参数前后顺序
test1('kevin',gender = 'male', age =37)
output: student name is kevin, he/she is 37, he/she is male
gender: male  name: kevin  age: 37

# 关键字参数2个要点：
# 1.关键字参数必须在位置参数之后
# 2.如果按照位置来，当一个参数被指定为关键字参数，它之后的参数必须也都是关键字参数 