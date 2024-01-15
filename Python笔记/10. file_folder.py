# 文件夹操作

import os

# rename(): 重命名
# 第一个参数为原文件名，第二个参数为更改后文件名
# 文件如果不存在则报错
os.rename('test[备份].txt', 'test3.txt')

# remove(): 删除文件
os.remove('test3.txt')


# 创建文件夹：mkdir()
# 如果文件夹已存在，则报错
os.mkdir('aa')

# 删除文件夹：rmdir()
# 删除和创建两个函数都是操作函数，不返回值
os.rmdir('aa')

# 重命名文件夹
# 使用方式一样，文件夹没有后缀，直接使用文件夹名即可
os.rename('aa', 'bbbb')

# 获取当前目录
# 这是一个返回函数，返回当前主目录名
print(os.getcwd())

# 获取目录列表
# 获取主目录内所有文件夹名，返回一个list
print(os.listdir())
# 参数中使用主目录内文件夹名，可以显示该文件夹下目录列表
print(os.listdir('aa'))  

# 更改默认目录
# 在主文件夹下创建aa文件夹，在aa文件夹内创建bb文件夹
os.mkdir('aa')
os.chdir('aa')  # 将操作目录更改为主文件夹下的aa文件夹
os.mkdir('bb')  # 在aa文件夹下创建bb文件夹

# 批量重命名，添加指定字符串
# 将bbbb文件夹下所有文件重命名
# 1. 找到所有文件
file_list = os.listdir('bbbb')
print(file_list)
os.chdir('bbbb') # 用来将操作位置更改为bbbb文件夹
# 构造新文件名
for i in file_list:
    # 用一个str来储存新的文件名
    new_name = 'Python_' + i
    # 通过rename来更改文件名，i为原文件名，new_name为更改后文件名
    os.rename(i , new_name)


# 批量重命名，删除指定字符串
file_list = os.listdir('bbbb')
print(file_list)
os.chdir('bbbb') # 用来将操作位置更改为bbbb文件夹
# 构造新文件名
for i in file_list:
    # 用一个str来储存删除指定字符串后的文件名
    index = i.rfind('_') 
    new_name = i[index+1:]
    # 通过rename来更改文件名，i为原文件名，new_name为更改后文件名
    os.rename(i , new_name)
