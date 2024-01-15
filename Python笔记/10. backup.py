# backup documents

from hashlib import new


old_file = input('输入要备份的文件名: ') + '.txt'
fin = open(old_file, 'r')


index = old_file.find('.')
# 在str的index里用冒号加上index，可以将该index开始的内容忽略
print(old_file[:index]) 

# 在str的index里用index加上冒号，可以将index之前的内容忽略
new_file = old_file[:index] + '[备份]'+old_file[index:]

print(new_file)

# 非文本文件可以通过rb，wb，2进制方式大概写入。
fout = open(new_file,'w')
fout.write(fin.read()) 

fin.close()
fout.close()

f = open('test1.txt','r')
print(f.read())

f.close()

# 如果只需要备份内容过长，可以通过while loop
while True:
    # 读取old file，并限制old file 读取范围
    con = old_file.read(1024)
    if len(old_file) == 0: # 判断old_file读取到所有内容
        break
    new_file.write(con)
