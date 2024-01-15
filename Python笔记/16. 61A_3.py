# exam

def count(element, box):
    """count how many times digit element appears in int box"""
    assert element >= 0 and element < 10
    box = abs(box)

    total = 0

    while box > 0:
        if box % 10 == element:
            total += 1
        
        box = box // 10
    
    return total 


def count_nine(element, box):
    """count how many times digital elment appears in the non-negative interger
    box in a place that is not next to a 9"""
    # assert为断言，程序只有在达到条件情况下会运行
    assert element >= 0 and element < 10
    assert box >= 0

    nine, total = False, 0

    while box > 0:
        # 条件判断：1.每位的余数和element相等
        # 2. nine，判断该位的右边不是9，数字9本身会被计算，所以第一次不为false
        #    只判断element的左边和右边是否是9
        # 3. (box // 10) % 10 == 9，判断该位的左边一位不为9
        if box % 10 == element and not(nine or (box // 10) % 10 == 9):
            total += 1
        # 如果当前位为9，设为True，下一次 not True会被判断为false，不进入if判断
        nine = box % 10 == 9
        # box缩进一位
        box = box // 10
    return total 

# 不能使用float，因为float求余数会保留小数位。
print(count_nine(-2, 314159265359))

# currying
from operator import add


print(add(2, 3))

def make_adder(n):
    print(n)
    return lambda x: n + x

# 第一个括号，作为父级参数n，第二个括号作为二级参数x
print(make_adder(2)(3))


# return whether every digit in pegs appears 
# at least as many times in holes as it does in pegs
# use the first question function

def fit(pegs, holes):
    i = 0

    while i <= 9:
        if count(i, pegs) > count(i, holes):
            return False
        i += 1
    return True

print(fit(314159,112233456789))