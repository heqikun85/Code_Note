
#用户输入
passWord = input('请输入你的密码：')
print(f'你输入的密码是 {passWord}')
print(type(passWord))

print(f'this is int {int(passWord)}, and this is float\
 {float(passWord)} \nafter all the type of passWord is {type(passWord)}')

print('''
   _____                   .__ .__     _____            __   
  /  _  \    ______  ____  |__||__|   /  _  \ _______ _/  |_ 
 /  /_\  \  /  ___/_/ ___\ |  ||  |  /  /_\  \\_  __ \\   __\-  
/    |    \ \___ \ \  \___ |  ||  | /    |    \|  | \/ |  |  
\____|__  //____  > \___  >|__||__| \____|__  /|__|    |__|  
        \/      \/      \/                  \/               
''')
#注意art中的反斜杠被动换行


x = int(1)   # x 输出结果为 1
y = int(2.8) # y 输出结果为 2
z = int("3") # z 输出结果为 3
print(f'type of all, x {x}\ny {y}\nz {z}')

x = float(1)     # x 输出结果为 1.0
y = float(2.8)   # y 输出结果为 2.8
z = float("3")   # z 输出结果为 3.0
w = float("4.2") # w 输出结果为 4.2
print(f'type of all, x {x}\ny {y}\nz {z}\nw {w}')

x = str("s1") # x 输出结果为 's1'
y = str(2)    # y 输出结果为 '2'
z = str(3.0)  # z 输出结果为 '3.0'
print(f'type of all, x {x}\ny {y}\nz {z}')

str1 = '1'
str2 = '2.1'
str3 = '(100, 200, 300)'
str4 = '[100, 200, 300]'
#str5 = {'name': 'kevin' , 'age': 37, 'weight': '148 lb'}

print(f'show all type: str1 is {type(eval(str1))}\n\
str2 is {type(eval(str2))}\nstr3 is {type(eval(str3))}\nstr4 is {type(eval(str4))}')

# 判断
str1 = 'kevin'
list1 = [1,2,3]
tuple1= (1,2,3)
dict1 = {'kevin': 32, 'angela': 27}
print(1 in list1)       # list能判断value是否存在
print(1 in tuple1)      # tuple能判断value是否存在
print('e' in str1)      # str能判断单个字符是否存在
print('kevin' in dict1) # dict能判断key是否存在
print(27 in dict1)      # dict不能判断key value是否存在