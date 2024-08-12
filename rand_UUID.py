# import uuid
# import random

# def generate_custom_uuid():
#     # 生成随机UUID
#     random_uuid = str(uuid.uuid4())
    
#     # 将UUID转换成目标格式
#     parts = random_uuid.split('-')
#     parts[1] = ''.join(random.choice('abcdefghijklmnopqrstuvwxyz') for _ in range(4))
#     custom_uuid = '-'.join(parts)
    
#     return custom_uuid

# def main():
#     # 生成100个随机UUID并打印
#     for _ in range(100):
#         print(generate_custom_uuid())

# if __name__ == "__main__":
#     main()



# import re

# # 输入文件名
# input_file = '/Users/kevinhe/IdeaProjects/3.txt'
# output_file = '/Users/kevinhe/IdeaProjects/4.txt'

# # 正则表达式模式，匹配177999900xx格式的数字
# pattern = r'177999900\d{2}'

# # 读取文件内容
# with open(input_file, 'r') as file:
#     content = file.read()

# # 替换符合模式的数字为一个空字符串
# new_content = re.sub(pattern, '', content)

# # 将结果写回新文件
# with open(output_file, 'w') as file:
#     file.write(new_content)

# print(f"处理完成，结果已写入 {output_file}")


# 输入文件名
input_file = '/Users/kevinhe/IdeaProjects/4.txt'

# 定义表名和字段名，不包括id字段
table_name = 'user'
fields = ['id','name', 'phone', 'email', 'profession', 'age', 'gender', 'status', 'createtime']

# 准备插入语句的前半部分
insert_prefix = f"INSERT INTO {table_name} ({', '.join(fields)}) VALUES "

# 读取文件内容并生成SQL语句
with open(input_file, 'r') as file:
    lines = file.readlines()

# 生成并打印SQL语句
for line in lines:
    # 使用split()以空格为分隔符分割字段
    values = line.strip().split()

    # 将各字段值按类型用引号包裹（字符串类型用引号，数字类型不需要）
    formatted_values = []
    for i, value in enumerate(values):
        # 根据字段类型判断是否需要引号
        if fields[i] in ['age', 'gender', 'status']:
            formatted_values.append(value)  # 不加引号
        else:
            formatted_values.append(f"'{value}'")  # 加引号

    # 拼接成SQL插入语句
    sql = f"{insert_prefix}({', '.join(formatted_values)});"
    
    # 打印SQL语句
    print(sql)