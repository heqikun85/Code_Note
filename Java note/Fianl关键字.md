## Java中的final关键字

1. **`final`关键字的基本用法**

　　在Java中，`final`关键字可以用来修饰类、方法和变量（包括成员变量和局部变量）。下面就从这三个方面来了解一下`final`关键字的基本用法。

    1. 修饰类

　　当用`final`修饰一个类时，表明这个类不能被继承。也就是说，如果一个类你永远不会让他被继承，就可以用`final`进行修饰。`final`类中的成员变量可以根据需要设为`final`，但是要注意`final`类中的所有成员方法都会被隐式地指定为`final`方法。
![IMAGE](https://images0.cnblogs.com/i/288799/201407/091032249893721.jpg)

在使用`final`修饰类的时候，要注意谨慎选择，除非这个类真的在以后不会用来继承或者出于安全的考虑，尽量不要将类设计为`final`类。

    2. 修饰方法

　　下面这段话摘自《Java编程思想》第四版第143页：

　　“使用`final`方法的原因有两个。第一个原因是把方法锁定，以防任何继承类修改它的含义；第二个原因是效率。在早期的Java实现版本中，会将`final`方法转为内嵌调用。但是如果方法过于庞大，可能看不到内嵌调用带来的任何性能提升。在最近的Java版本中，不需要使用`final`方法进行这些优化了。“

　　因此，如果只有在想明确禁止 该方法在子类中被覆盖的情况下才将方法设置为`final`的。

　　注：类的`private`方法会隐式地被指定为`final`方法。

    3. 修饰变量

　　修饰变量是`final`用得最多的地方，也是本文接下来要重点阐述的内容。首先了解一下`final`变量的基本语法：

　　对于一个`final`变量，如果是基本数据类型的变量，则其数值一旦在初始化之后便不能更改；如果是引用类型的变量，则在对其初始化之后便不能再让其指向另一个对象。

　　举个例子：
![IMAGE](https://images0.cnblogs.com/i/288799/201407/091114508325258.jpg)

上面的一段代码中，对变量`i`和`obj`的重新赋值都报错了。


2. **深入理解`final`关键字**

　　在了解了`final`关键字的基本用法之后，这一节我们来看一下`final`关键字容易混淆的地方。

    1. 类的`final`变量和普通变量有什么区别？

　　当用`final`作用于类的成员变量时，成员变量（注意是类的成员变量，局部变量只需要保证在使用之前被初始化赋值即可）必须在定义时或者构造器中进行初始化赋值，而且final变量一旦被初始化赋值之后，就不能再被赋值了。

　　那么`final`变量和普通变量到底有何区别呢？下面请看一个例子:
```JAVA
    public class Test {
        public static void main(String[] args)  {
            String a = "hello2"; 
            final String b = "hello";
            String d = "hello";
            String c = b + 2; 
            String e = d + 2;
            System.out.println((a == c));
            System.out.println((a == e));
        }
    }
        
    OUTPUT: true
            false
```

大家可以先想一下这道题的输出结果。为什么第一个比较结果为`true`，而第二个比较结果为`fasle`。  
这里面就是`final`变量和普通变量的区别了。  
当`final`变量是基本数据类型以及`String`类型时，如果在编译期间能知道它的确切值，则编译器会把它当做编译期常量使用。也就是说在用到该`final`变量的地方，相当于直接访问的这个常量，不需要在运行时确定。这种和C语言中的宏替换有点像。  
因此在上面的一段代码中，由于变量`b`被`final`修饰，因此会被当做编译器常量，所以在使用到`b`的地方会直接将变量`b` 替换为它的值。而对于变量`d`的访问却需要在运行时通过链接来进行。  
想必其中的区别大家应该明白了，不过要注意，只有在编译期间能确切知道`final`变量值的情况下，编译器才会进行这样的优化，比如下面的这段代码就不会进行优化：

    ```JAVA
    public class Test {
        public static void main(String[] args)  {
            String a = "hello2"; 
            final String b = getHello();
            String c = b + 2; 
            System.out.println((a == c));
    
        }
        
        public static String getHello() {
            return "hello";
        }
    }
    ```

　　这段代码的输出结果为false。

    2.被final修饰的引用变量指向的对象内容可变吗？

　　在上面提到被`final`修饰的引用变量一旦初始化赋值之后就不能再指向其他的对象，那么该引用变量指向的对象的内容可变吗？看下面这个例子：

    ```JAVA
    public class Test {
        public static void main(String[] args)  {
            final MyClass myClass = new MyClass();
            System.out.println(++myClass.i);
    
        }
    }
    
    class MyClass {
        public int i = 0;
    }
    ```

　　这段代码可以顺利编译通过并且有输出结果，输出结果为`1`。这说明引用变量被`final`修饰之后，虽然不能再指向其他对象，但是它指向的对象的内容是可变的。

    3.final和static

　　很多时候会容易把`static`和`final`关键字混淆，`static`作用于成员变量用来表示只保存一份副本，而`final`的作用是用来保证变量不可变。看下面这个例子：

```JAVA
public class Test {
    public static void main(String[] args)  {
        MyClass myClass1 = new MyClass();
        MyClass myClass2 = new MyClass();
        System.out.println(myClass1.i);
        System.out.println(myClass1.j);
        System.out.println(myClass2.i);
        System.out.println(myClass2.j);

    }
}

class MyClass {
    public final double i = Math.random();
    public static double j = Math.random();
}
```

　　运行这段代码就会发现，每次打印的两个`j`值都是一样的，而i的值却是不同的。从这里就可以知道`final`和`static`变量的区别了。

    4.匿名内部类中使用的外部局部变量为什么只能是final变量？

　　这个问题请参见上一篇博文中《Java内部类详解》中的解释，在此处不再赘述。

    5.关于 final 参数的问题

　　关于网上流传的”当你在方法中不需要改变作为参数的对象变量时，明确使用`final`进行声明，会防止你无意的修改而影响到调用方法外的变量“这句话，我个人理解这样说是不恰当的。

　　因为无论参数是基本数据类型的变量还是引用类型的变量，使用`final`声明都不会达到上面所说的效果。

　　看这个例子就清楚了：
![IMAGE](https://images0.cnblogs.com/i/288799/201407/091522525043726.jpg)

　　上面这段代码好像让人觉得用final修饰之后，就不能在方法中更改变量i的值了。殊不知，方法`changeValue`和`main`方法中的变量i根本就不是一个变量，因为java参数传递采用的是值传递，对于基本类型的变量，相当于直接将变量进行了拷贝。所以即使没有`final`修饰的情况下，在方法内部改变了变量`i`的值也不会影响方法外的`i`。

　　再看下面这段代码：
```java
public class Test {
    public static void main(String[] args)  {
        MyClass myClass = new MyClass();
        StringBuffer buffer = new StringBuffer("hello");
        myClass.changeValue(buffer);
        System.out.println(buffer.toString());
    }
}
 
class MyClass {
     
    void changeValue(final StringBuffer buffer) {
        buffer.append("world");
    }
}
```

　　运行这段代码就会发现输出结果为` helloworld`。很显然，用`final`进行修饰并没有阻止在`changeValue`中改变`buffer`指向的对象的内容。有人说假如把`final`去掉了，万一在`changeValue`中让`buffer`指向了其他对象怎么办。有这种想法的朋友可以自己动手写代码试一下这样的结果是什么，如果把`final`去掉了，然后在`changeValue`中让`buffer`指向了其他对象，也不会影响到`main`方法中的`buffer`，原因在于java采用的是值传递，对于引用变量，传递的是引用的值，也就是说让实参和形参同时指向了同一个对象，因此让形参重新指向另一个对象对实参并没有任何影响。

