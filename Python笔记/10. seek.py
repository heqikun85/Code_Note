# seek()

# 语法： 文件对象.seek（偏移量，起始位置）
# 0开头，1当前，2结尾

f = open('test.txt', 'r+')

f.seek(2,0) # 文件从开头位置偏移2个字符后，前两个字符不读取。

f.seek(2,1) # 这行会报错，暂时不知道原因。

f.seek(0,2) # 将指针移到结尾。无法读取文件。

print(f.read())

f.close()

f = open('test.txt', 'a+')

f.seek(0,0) # 将add的指针移到开头

f.seek(0) # 可以省略偏移量，默认为0

f.write('aaa') # write的指针和seek是独立的，seek移动了指针，write仍然从结尾处开始添加

print(f.read())  # 指针移到开头后，可以读取文件。

f.close()
