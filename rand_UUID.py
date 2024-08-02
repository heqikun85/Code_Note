import uuid
import random

def generate_custom_uuid():
    # 生成随机UUID
    random_uuid = str(uuid.uuid4())
    
    # 将UUID转换成目标格式
    parts = random_uuid.split('-')
    parts[1] = ''.join(random.choice('abcdefghijklmnopqrstuvwxyz') for _ in range(4))
    custom_uuid = '-'.join(parts)
    
    return custom_uuid

def main():
    # 生成100个随机UUID并打印
    for _ in range(100):
        print(generate_custom_uuid())

if __name__ == "__main__":
    main()