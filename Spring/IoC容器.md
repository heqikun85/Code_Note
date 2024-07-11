[返回概念](./Spring概念.md)

# IoC Container IoC容器

### 配置一个bean
在[maven结构]()main -- resources，创建 fileName.xml，并编写一段代码：
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