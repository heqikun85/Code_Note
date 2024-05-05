# 文件操作

# w模式，如果没有文件则会创建文件。
# 文件默认创建路径为vs code的打开主文件夹。
# 在我现在的电脑里，为comsc这个文件夹
f = open('test.txt', 'w')

# 读写操作 write() read()
# 在文件中写入aaa
f.write('aaa')

# 关闭文件
f.close()

# r模式 read only
f = open('test.txt','r')  # 如果没有文件，则会报错
f.close()

# w模式 write only
f = open('test.txt','w') # 如果文件不存在，则会新建文件
f.write('bbb')           # 删除原数据，写入新数据
f.write('a')             # 如果在没有关闭文件的情况下，再次写入则添加在之前内容之后
f.close() 

# a模式 add
f = open('2.txt', 'a')    # 如果文件不存在，则新建文件
f = open('test.txt', 'a') # 文件存在，在原文件内容后，添加内容
f.write('ccc')
f.close()

# 访问模式参数是否可以省略
# 访问模式可以省略，但默认为r模式。如果文件不存在则报错
f = open('test.txt')    

# read()
f = open('test.txt','r')

# read不写参数标识读取所有
print(f.read())  # 将文件内数据列印出来，并包括换行
# read()是一个累加函数，以下代码不会运行，因为上面的代码已经将文件内所有内容都读取了
# 如果此行代码放在f.read()之前，则会运行，并且f.read()会跳过之前已经读取过的内容
# f.read()内的参数为字符数，注：换行符也算一个字符
print(f.read(10))

# readlines(), 以行为单位读取文件内容
# 返回list，一行为一个list元素，并且包含换行符。注：最后一行如果没有换行则不包含换行符
print(f.readlines())

# readline()
print(f.readline())  # 它也是个累加函数，只要文件不关闭，之前读取的内容会被记录
print(f.readline())  # 再次读取会将第一次读取的内容跳过。读取之后的内容
print(f.readline(3)) # 参数为读取改行多少字符, 如果该行没有显示完，再次读取时会继续显示该行内容。
print(f.readline(10)) # 即便超过该行总字符数，也只显示一行的内容，不会向下显示

f.close()