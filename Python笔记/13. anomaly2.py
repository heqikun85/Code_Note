# 异常传递
import time

try:
    f = open('test.txt')
    try:
        while True:
            con = f.readline()
            # 如果读取完成退出循环
            if len(con) == 0:
                break
        
            # 和c语言中的sleep()类似
            # 是time模块的功能
            time.sleep(3)
            print(con)
    except:
        # 在命令提示符中如果按下ctrl+c（只在cmd模式下）结束终止的键
        print('程序被以外终止')

except:
    print('该文件不存在')


# 自定义异常

# 自定义异常类，继承Exception
class ShortInputError(Exception):
    def __init__(self, length, min_len):
        self.length = length
        self.min_len = min_len

    # 设置抛出异常的描述信息
    def __str__(self):
        return f'你输入的长度是{self.length}, 不能少于{self.min_len}个字符'

def main():
    # 尝试执行：用户输入，如果长度小于3，则抛出异常
    try:
        con = input('请输入密码： ')
        if len(con) < 3:
            # 抛出异常：通过raise语句抛出异常，并执行自定义异常函数
            raise ShortInputError(len(con), 3)
    # 自定义异常函数继承了Exception，所以可以抛出异常描述信息
    except Exception as result:
        print(result)
    else:
        print('密码设置完成')
    
main()