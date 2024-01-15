# operator 模块
from operator import *

# 1. 逻辑操作符
a = -1
b = 5

print('a =', a)
print('b =', b)
print()

print('not_(a)     :', not_(a))
print('not_(b)     :', not_(b))
print('truth(a)    :', truth(a))
print('is_(a, b)   :', is_(a, b))
print('is_not(a, b):', is_not(a, b))


# 2. 比较操作符
a = 1
b = 5.0

print('a =', a)
print('b =', b)

for func in (lt, le, eq, ne, ge, gt):
    print(f'{func.__name__}(a, b): {func(a, b)}')

a = 1
b = 5.0
lt(a, b): True
le(a, b): True
eq(a, b): False
ne(a, b): True
ge(a, b): False
gt(a, b): False


# 3. 算数操作符
a = -1
b = 5.0
c = 2
d = 6

# code                                          # output
print('\n正数/负数:')
# 返回 obj 的绝对值。
print('abs(a):', abs(a))                        abs(a): 1
# 返回 obj 取负的结果 (-obj)
print('neg(a):', neg(a))                        neg(a): 1
print('neg(b):', neg(b))                        neg(b): -5.0
# 返回 obj 取正的结果 (+obj)
print('pos(a):', pos(a))                        pos(a): -1
print('pos(b):', pos(b))                        pos(b): 5.0

print('\n算术:')
# 对于数字 a 和 b，返回 a + b
print('add(a, b)     :', add(a, b))             add(a, b)     : 4.0
# 返回 a // b, 向下取整，如果其中有一个数为float
# 则返回float格式，否则返回int
print('floordiv(a, b):', floordiv(a, b))        floordiv(a, b): -1.0
print('floordiv(d, c):', floordiv(d, c))        floordiv(d, c): 3
# 返回 a % b，mod是余数的意思，remind
print('mod(a, b)     :', mod(a, b))             mod(a, b)     : 4.0
# 对于数字 a 和 b，返回 a * b
print('mul(a, b)     :', mul(a, b))             mul(a, b)     : -5.0
# 返回c的d次方
print('pow(c, d)     :', pow(c, d))             pow(c, d)     : 64
# 返回 a - b
print('sub(b, a)     :', sub(b, a))             sub(b, a)     : 6.0
# 返回 a / b 例如 2/3 将等于 .66 而不是 0。
# 这也被称为“真”除法。
print('truediv(a, b) :', truediv(a, b))         truediv(a, b) : -0.2
print('truediv(d, c) :', truediv(d, c))         truediv(d, c) : 3.0

print('\n按位:')
# 类似a & b，两数中较小的那个会被较大的那个包含
print('and_(c, d)  :', and_(c, d))              and_(c, d)  : 2
# 按位取反，但正数从0开始，所以正数取反会高一位
# 负数取反会少一位，invert(-1)就是0
print('invert(c)   :', invert(c))               invert(c)   : -3
# a << b
print('lshift(c, d):', lshift(c, d))            lshift(c, d): 128
# a | b
print('or_(c, d)   :', or_(c, d))               or_(c, d)   : 6
# a >> b
print('rshift(d, c):', rshift(d, c))            rshift(d, c): 1
# a ^ b
print('xor(c, d)   :', xor(c, d))               xor(c, d)   : 4

