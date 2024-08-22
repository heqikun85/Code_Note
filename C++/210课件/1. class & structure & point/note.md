structure的标准形式是
```c++
struct “name”
{
 内容（code） 
} ;
class的标准形式
class “name”
{
内容 （code）
};
```

struct所有的内容都是public的，在structure和class里的内容，不需要按照从上往下的顺序才能读取，class内一般以public的内容优先，private的内容为后

class分为public和 private，public内容，为所有function都可以调用，private的内容只有class本身可以调用。[链接](https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm)

structure和class可以作为头文件使用，例如：我们可以创建一个class，储存为note.h文件，
```c++
class name{
	public:
		void init( int age, bool check){
			m_age= age;
		}

		bool check(){
			if(m_age > 50)
				return false;
			return true;
		}
	private:
		int m_age;
		bool m_check;
	};
```

如果main function忘记调用 void init 这个function，m_age会随机出现数字
我们可以用另一种语法避免这个问题

```c++
class name{
public:
	name (int age, bool check){
		m_age= age;
	}
};

```

使用class的名字后面直接跟括号和reference，这样在main函数内，只需要用class定义一个项目，在项目后面跟括号加reference就可以直接初始化class内variable的数据了。
也可以把他放在类申明之外

```c++
class name{
public:
	name ( int age, bool check);
	bool check(){
		if(m_age > 50)
			return false;
		return true;
	}
private:
	int m_age;
	bool m_check;
};

Name :: name ( int age, bool check)
{
		m_age= age;
	}
```

等于把类名本身作为一个function title，然后在class内留一个property。

这种方式同样有overload的用法

```c++
name ( int age, bool check);
name( );

name :: name ( int age, bool check)
name:: name

// class 也可作为定义一个pointer，但pointer要指向一个新的值，如果不指向新的值，就只是一个空pointer。

int main（）｛
		Name carey（40，false）；bill；
		Name carey[5]; // ARRAY 不能跟 element
		Name *ptr = new name（40，false）；
		Name *ptr； //只是一个pointer
		
        ~name（）// 这个function用来释放多余的内存，销毁之前的数据，可以作为function自己打代码在function内，也可以直接写一个function框架，留空后c++会运行默认销毁代码。

        // 使用new 代码创建一个新的memory时，一定要在结束时delete；
        ~name( )
        //这里会运行默认在之前class的variable定义
        {
        // 在内容里打上其他class或者的内容后，先运行该内容，然后删除该内容
        }
        //这里会销毁function内运行的内容，然后运行~name property里运行的内容
｝

``

如果被调用的class 内的函数没有初始化，调用的时候就会出错，我们可以在调用的function括号后用 冒号 在加上 class定义的方式，添加初始值。
