package 包

要使用包文件夹内的模块，需要在模块名前加上包名的前缀
from mypackage.my_module import *

add(1, 2)
multip(2, 3)

# 方法二：可以通过 from 包名 import *
# 这个方式必须设置包文件夹内的__init__.py文件
# 必须在文件中的__all__列表，添加允许使用的功能
from mypackage import *

# 这种方式，调用时需要将module名加入才能调用功能
my_module.divide(12, 6)
