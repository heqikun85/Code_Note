# 异常 anomaly

try:
    可能发生错误的代码

except type_of_anomaly:
    如果出现异常执行的代码


try:
    # 如果没有test1.txt文件，跳过try语句下的所有代码
    f = open('test1.txt','r')
    print(f.read())
except:
    # 如果跳过try代码，则运行except以下代码
    f = open('test1.txt','w')
    f.write('abdcsdfa\nasdfadf\nadfaaerq')

try:
    # 如果try语句可以运行，则运行try语句下代码
    f = open('test1.txt','r')
    print(f.read())
except:
    f = open('test1.txt','w')

f.close()


# 此行代码会报错，因为num undefined
# 异常类型：NameError
try:
    print(num)
except NameError:
    # 这行代码也会有错，0不可为除数
    # 异常类型：ZeroDivisionError
    print(1/0)
# 一个try只能跟一个except
except ZeroDivisionError:
    print('no error')


try:
    print(num)
    print(1/0)
except (NameError,ZeroDivisionError):
    print('no error')


# 捕获异常描述信息
try:
    print(num)
except(NameError, ZeroDivisionError) as result:
    print(result)

# 捕获所有异常
try:
    print(1/0)
    print(num)
except Exception as result:
    print(result)

try:
    f = open('test1.txt', 'r')
except Exception as result:
    print(result)
    f = open('test1.txt', 'w')
    f.write('adkfj\nckjad\nqpoieur\nyiuzo\neq[jklz')
else:
    print(f.read())
finally: # 无论是否有错误，最终都会运行finally代码
    f.close()