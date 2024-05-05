## Java method
由于java和C++最大的区别就是对class的应用上，Java是建立在class的基础上  
所以Java的method其实可以理解为C++内的一个function

1. 方法的定义格式
    和C++一样，方法分为public 和 private
```JAVA
    public static 返回值类型 方法名（参数）{
        方法函数；
        return 返回值；
    }
```
2. 方法的调用
    method写在main method之外，如果是在同一个文件的同一个class中，直接在main函数中使用method名调用。  
    ***main函数为static，所以调用的method也必须为static***

3. 重载方法
    we could use same name to build mutiple methods
    ```java
    public static int sum(int a, int b)
    public static int sum(int a, int b, int c)
    public static int sum(double a, double b)
    ```
    由于参数类型或数量的不同，我们可以通过参数来区分同名字下的不同方法。


## 面向对象 object-oriented

class 类：是object共同特性的描述  
object 对象：是真实存在的具体东西  
在Java中，必须先设计类，才能获得对象。

define an class：
```JAVA
public class 类名{
    member variable
    member method
    constructor
    code block
    inner class
}
```
Java的类可以在同一个package内不同的文件下。调用都是在main function内调用。调用时需要给class先赋值

Main class，我们可以创建多个不同的对象
```JAVA
public class PhoneTest {
    public static void main(String[] args){
        Phone p = new Phone(); // 在main函数中创建一个新的对象
        p.brand = "Apple"; // 给对象赋值
        p.price = 799.99;

        System.out.println(p.brand + " " + p.price);
    }
}
```
对象类
```JAVA
public class Phone {
    String brand;
    double price;

    public void call(){
        System.out.println("this phone is used");
    }

    public void playGame(){
        System.out.println("this phone is played game");
    }
}
```
