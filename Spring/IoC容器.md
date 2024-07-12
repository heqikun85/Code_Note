[返回概念](./Spring概念.md)

# IoC Container IoC容器

[依赖注入](#table1)
[Bean适用范围](#table2)

### 配置一个bean
在[maven结构](./Spring概念.md) : main -- resources，创建 fileName.xml，并编写一段代码：
```java
//单独配置式
<bean class="addressName" id="idName2"/>

// 配置属性式
<bean class="cn.xunzheng.beans.User" id="idName1">
    /*
     * 配置class和object之间的关系。
     * property：标示当前bean的属性，
     * name：标示具体哪个属性
     * ref：标示参照哪个bean
     */
    <property name="objectAttribute" ref="idName2" />
</bean> 
```
class后的地址就是User.java文件的相对路径（在同一个project目录下）
配置的是实现类，不是接口。Spring要直接创建对象，需要class有具体方法。
id是用于之后的调用。

可以通过test--java文件夹内创建test文件来测试

调用配置文件的Type：`ApplicationContext`
new的Type：`ClassPathXmlApplicationContext`
```java
@Test // Test的注释，需要导入JUnit的jar包
public void test01(){
    /* 
     * 创建IoC容器，并加载我们的配置文件
     * ClassPathXmlApplicationContext：根据项目路径的xml配置实例化Spring容器。
     * FileSystemXmlApplicationContext：根据磁盘目录的xml配置实例化Spring容器
     */
    ApplicationContext ioc = new ClassPathXmlApplicationContext("文件名.xml");
    // 获取Bean：1.通过className.class来获取Bean
    //          2.通过idName来获取bean，但无法获取Bean的Type，需要强制转换
    // User bean = (User) ioc.getBean("user");
    User bean = ioc.getBean("User.class");
    System.out.println(bean);
}
```


### <a id="table1">依赖注入</a>

依赖注入就是注入Bean中的属性。用来描述Bean是干什么的
依赖注入（‌Dependency Injection，‌简称DI）‌的核心思想是，‌一个对象不再负责创建或查找它所依赖的对象，‌而是通过外部传递这些依赖关系。‌

1. 基于Setter的依赖注入
```java
// 通过property 对每一个属性赋值。我觉得这种方法会需要更改xml文件，不是很好的方式。
<bean class="com.yardLand.main.User" id="user1">
    <property name ="id" value="1"></property>
    <property name ="userName" value="许庶"></property>
</bean>
```

2. 基于Constructor的依赖注入
   1.  可以省略name属性，但需要构造顺序与构造函 数的参数顺序相同。
   2.  也可以用index或type来构造。

![bean配置](./image/1720768940129.jpg)

```java
// 通过constructor的依赖注入，必须把所有属性都注入，否则会报错
<bean class="com.yardLand.main.User" id="user1">
    <constructor-arg name="id" value="金城武"></constructor-arg>
    <constructor-arg name="userName" value="金城武"></constructor-arg>
    <constructor-arg name="realName" value="金城武"></constructor-arg>
</bean>

//各种形式的注入
<bean class="com.yardLand.main.User" id="user1">
    <property name="user" value="1"></property>

    
    <!--设置null-->
    <property name="name">
        <null></null>
    </property>
    
    <!--引用外部Bean, ref为外部bean的id-->
    <property name="name" ref="wife"></property>
    
    <bean class="XXXXXX" id="wife">
        <property name="age" value="18"></property>
        <property name="name" value="迪丽热巴"></property>
    </bean>
   
    <!--使用内部bean来依赖注入-->
    <property name="wife">
        <bean class="XXXXXX">
            <property name="age" value="18"></property>
            <property name="name" value="迪丽热巴"></property>
        </bean>
    </property>
    
    <!--list/map属性注入
        type是数据类型, list就用<value>，map就用<entey>
        list的bean要用<bean>包裹,map用<entry value-ref="xxx">-->
    <property name="habby">
        <list>
            <!--每一个value块代表list内一个element-->
            <value>StringValue</value>
            <value>StringValue2</value>
        </list>
    </property>

    <property name="habby">
        <map>
            <entry key="1" value="1"></entry>
        </map>
    </property>
</bean>
</bean>
```

Setter方式有一个P命名空间的简化方式（不支持集合）
Constructor有一个C命名空间。

### <a id="table2">Bean作用域</a>

Spring框架在IoC容器内创建Bean默认是单例，创建一次后不会再继续创建。甚至两个不同变量名也不会更改。如果需要创建多例，代码如下
```java
// scope内一共就两个选项：singleton/prototype
<bean id="name" class="xxxxx" scope="xxx">
```
默认是singleton，使用prototype后，IoC创建的Bean就不会是单例了。

### IoC配置Bean的实用性
适合交给IoC容器管理的bean？
1. 表现层对象（Presentation Layer Objects）
    表现层对象是用于与用户进行交互的对象，它们负责接收用户的输入并将数据呈现给用户。它们通常存在于应用程序的用户界面部分。<br></br>
    
    **作用**：
    接收用户的输入（如表单数据、按钮点击）。
    调用业务层对象处理逻辑。
    显示业务层返回的结果（如网页、桌面应用程序的UI）。<br></br>

    **示例**：

    在一个MVC（Model-View-Controller）架构中，表现层对象通常是Controller和View。<br></br>

2. 业务层对象（Business Layer Objects）
    业务层对象负责应用程序的核心业务逻辑和规则。它们处理从表现层接收到的数据，并与数据层交互来完成实际的操作。<br></br>


3. 数据层对象（Data Layer Objects）
4. 工具对象（Utility Objects）
   

不适合由IoC容器管理的bean
1. 封装实体的域对象（Domain Objects Encapsulating Entities）

