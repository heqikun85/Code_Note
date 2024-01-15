# 函数进阶
# 需求：进入系统显示系统功能界面，功能如下：
# 1. 添加学员
# 2. 删除学员
# 3. 修改学员信息
# 4. 查询学员信息
# 5. 显示所有学员信息
# 6. 退出系统

# 首先创建首页界面显示
def system_interface():
    print('-'*20)
    print(f'1. 添加学员\n2. 删除学员\n3. 修改学员信息\
        \n4. 查询学员信息\n5. 显示所有学员信息\n6. 退出系统')
    print('*'*20)


# 存储所有学员信息
info = []

# 添加学员信息函数
def add_info():
    '''add student info'''
    global info
    
    new_id = input('请输入学号：')
    new_name = input('请输入姓名：')
    new_tel = input('请输入电话：') 
    
    for i in info:
        if new_name == i['name']:
            print('the student has been in the system')
            return
    
    info_dict = {'id': new_id, 'name': new_name, 'tel': new_tel}

    info.append(info_dict)
    
    print('the student information has been add into system.')


# 删除学员信息函数
def del_info(name):
    """delete student information"""
    global info
    
    for i in info:
        if name == i['name']:
            info.remove(i)
            print('the student infromation has been delete.')
            break
    else:
        print('the student not in system.')


def modify_info():
    """modify student information"""
    global info
    modify_in = input("please enter the student's info that you want to modify information: ")
    modify_dict = {}

    for i in info:
        if modify_in == i['name']:
            modify_dict = i
            break
        elif modify_in == i['id']:
            modify_dict = i
            break
        elif modify_in == i['tel']:
            modify_dict = i
            break
    else:
        print('the student are not in the system')
        return

    print('-'*20)
    print(f'1. modify the student id\n2. modify the student name\
        \n3. modify the student telphone number')
    print('*'*20)

    choose2 = int(input('输入你想要进行操作的序列号： '))

    while True: 
        if choose2 == 1:
            modify_dict['id'] = input('Please enter the new id: ')
            print("the student's id has been modified")
            break
        elif choose2 == 2:
            modify_dict['name'] = input('Please enter the new name: ')
            print("the student's name has been modified")
            break
        elif choose2 == 3: 
            modify_dict['tel'] = input('please enter the new tel: ')
            print("the student's tel has been modified")
            break
        else:
            choose2 = int(input('You enter a wrong number. Please enter again: '))
    
def search_info():
    """search specific student info"""
    search_in = input('enter the student info which you want to search: ')

    for i in info:
        if search_in == i['name']:
            print(f"student id: {i['id']}, name: {i['name']}, tel: {i['tel']}")
            break
        elif search_in == i['id']:
            print(f"student id: {i['id']}, name: {i['name']}, tel: {i['tel']}")
            break
        elif search_in == i['tel']:
            print(f"student id: {i['id']}, name: {i['name']}, tel: {i['tel']}")
            break          
    else:
        print('the student are not in the system.')


# while True loop，只要为True的情况下，重复运行loop内代码
while True:
    # 调用首页界面
    system_interface()

    choose = int(input('输入你想要进行操作的序列号： '))

    # 添加学员信息
    if choose == 1:
        add_info()        
    
    # 删除学员信息
    elif choose == 2:
        del_name = input('请输入你要删除的学员名字： ')
        del_info(del_name)
   
    # 修改学员信息
    elif choose == 3:
       modify_info()
   
    # 查询学员信息
    elif choose == 4:
        search_info()
   
    # 显示所有学员信息 
    elif choose == 5:
        if len(info) == 0:
            print('the system is empty')
        else:
            for i in info:
                 print(f"student id: {i['id']}, name: {i['name']}, tel: {i['tel']}")    
    
    # 退出系统
    elif choose == 6:
        print('the system is end')
        break
   
    else:
        print('你输入的序号错误！请重新输入.')


