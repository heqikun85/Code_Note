# 模块，此部分还有一个示例在 my_module.py文件中

# 1. 导入模块方法一
import math

from Python学习.my_module import multip

# 调用功能
# math module中的根号计算function,返回一个float值
a = math.sqrt(9)

# 2. 导入模块方法二
from math import sqrt

# 通过这种方式导入的模块，不需要调用模块名，只需要功能名
a = sqrt(9)

# 3. 导入模块方法三
from math import *

# 通过这种方式导入的模块，不需要调用模块名，只需要功能名
a = sqrt(9)

# 4. 导入模块方法四
import math as qq

# 使用别名后，调用module时需要用别名取代module_name
a = qq.sqrt(9)
print(a)

#5. 导入模块方法五
from math import sqrt as qq

# 使用别名后，调用function时需要用别名取代function_name
a = qq(9)


# 使用自定义模块

from my_module import *

add(1, 2)
multip(2, 3)