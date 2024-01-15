# deep return value 多return value

def doubleReturn():
    dict1 = {'kevin': 2, 'angela': 3}
    dict2 = {'siming': 2, 'zhuxun': 3}
    return dict1, dict2    # use comma to split the two return value

a = doubleReturn()

print(type(a))  # <class 'tuple'>
print(a)        # ({'kevin': 2, 'angela': 3}, {'siming': 2, 'zhuxun': 3})


def doubleReturn1():
    dict1 = 'kevin'
    dict2 = 'siming'
    return {dict1: dict2}

print(type(doubleReturn1())) # <class 'dict'>
print(doubleReturn1())       # {'kevin': 'siming'}

def test1():
    return [1, 3]   # 这个就返回的是list

