[返回目录](./1.%20java学习目录.md)

## 继承 inherent

Object 代表什么？  
object就是封装对应的数据，并提供数据对应的行为。理解起来还是有点飘渺的，结合实际就是。
1. 将需要处理的数据，在一个class文件中列出，成为该object的一个attribute。
2. 对该attribute的获取是 get function，修改是 set function，这就是对应的行为。
3. 一个class中所有attribute and function的结合成一个整体，就是一个object。
4. object的list就是对象的集合。

如果不同的class有多个相同的attibute怎么办？
使用java继承的逻辑从parent class 继承相应的attribute
1. java 关键字 `extends` 让两个class建立起继承关系。
    `public class Student extends Person{}`
2. Student 称为 child class，Person 为 parent class。
3. Java只支持单继承，也就是一个class只能继承一个class，不能从多个class继承。
4. 继承可以是多层的，也就是一个parent class可以有多个child class，而child class也可以有多个child class。
5. Java中所有的class都直接或间接继承与Object class。

什么时候使用继承？  
当multiple class之间存在共性内容，并且child class是 parent class的一种，就可以考虑继承来优化代码。

实例 - 一个继承关系图：
![image]()

