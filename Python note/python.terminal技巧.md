python：可以在Mac下用BBEdit编辑代码，然后用terminal 运行，terminal的操作有另一个文件。

Print  “ 后面加内容 ”，引号内的内容就会被编译。
	单引号内也是一样效果，单引号内的双引号也会被显示出来

#， 井号后为注释内容，#后的内容不会被编译器编译，读：octothorpe

· +	plus		加号		
· -	minus		减号
· /	slash		斜杠 / 除号
· *	asterisk	星号 / 乘号
· %	percent	百分号 （和c++一样，是除法后的余数）
· <	less-than	小于号
· >	greater-than		大于号
· <=	less-than-equal	小于等于号
· >=	greater-than-equal	大于等于号 

Python可以在print后用逗号分隔，直接显示计算式所得的结果。或者直接在print后跟计算式。
和C++一样，除法是分int和double的，但是不需要像C++那样提前对数据分类，如果要四舍五入，直接用整数形式，如果要保留小数，显示7.0即可。并且除法中任何一个数字加小数点都可以。不限小数点后几位。
Operation 符号直接判断为条件判断符号，会判断符号前后的对错，显示true or false。
Python 设定变量只需要命名和赋值，不需要对命名的变量提前设定变量类型。
在引号内有一个操作，”%s” , 这个代码能将后置的文字显示在这一部分
比如 "hey %s there" % "you" 显示出来的是 hey you there

# Terminal使用
文件目录
首先要清楚几个文件目录：

" / "  ：根目录

" ~ " ：用户主目录的缩写。例如当前用户为hello，那么" ~ "展开来就是：/Users/hello

" . "  ：当前目录

".."   ：父目录





命令
然后说一下最基本的几个命令。

1.cd 跳转到某个目录
例如：


$ cd /Users/apple/Desktop/

在这里有个小技巧，就是在输入目录如Desktop时，只要输入Des并按tab键，该目录名便自动补全了。
其中

cd /   表示跳转到根目录。

cd ~   表示跳转到用户主目录。

cd ~apple   表示跳转到用户apple的主目录。

cd ..   表示跳转到上级目录。（cd和..之间的空格不能漏）



2.ls 列出当前目录下的子目录和文件
例如：


$ ls
Desktop		Downloads	Movies		Pictures	build
Documents	Library		Music		Public		log.txt


3.pwd 显示当前目录的路径
为了验证上面所说的几个特殊目录的路径，我们可以用pwd命令将其输出看看。例如：


$ cd /
$ pwd
/
$ cd ~
$ pwd
/Users/apple
$ cd ./Desktop/
$ pwd
/Users/apple/Desktop
$ cd ..
$ pwd
/Users/apple
$ cd ./Desktop/iRoot/
$ pwd
/Users/apple/Desktop/iRoot
$ cd ~apple/
$ pwd
/Users/apple
$ cd ~/Music/
$ pwd
/Users/apple/Music


4.clear 清空当前输入
如果Terminal窗口中的内容太多了，可以用clear命令将其清空。



5.history 查看输入历史记录
在Terminal输入命令时，可以使用上下方向键查看之前输入的命令（和windows的cmd相同）。另外，可以用history查看输入的完整历史，例如我的Terminal中的部分历史记录输出如下：


  600  ls
  601  cd Public/
  602  ls
  603  cd /
  604  ls
  605  cd ..
  606  ls
  607  cd /
  608  ls
  609  history 
  610  history

————————————————
版权声明：本文为CSDN博主「Jymn_Chen」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u010962810/java/article/details/20370617