# 函数说明文档
# help函数自动有print效果，参数为function，返回参数中函数的说明
help(len)


# 定义函数说明文档
def function_name(argument):
    """说明文档位置"""  # 只有第一行写的多行注释内容才会作为函数说明文档被help调用。


def sum_num(a, b):
    """求和函数"""
    return a + b


help(sum_num)  # output sum(a, b) 求和函数


def sum(a , b):
    '''
    求和函数
    :param a: 参数1
    '''
    return a+b