package org.example;

import org.example.dao.SpringDao;
import org.example.service.SpringService;
import org.example.service.Impl.SpringServiceImpl;
import org.springframework.context.*;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class Main{
    public static void main(String[] args) {
        ApplicationContext ctx = new ClassPathXmlApplicationContext("application.xml");
        // 三种调用Bean的形式。注意，后两种必须用object实例文件名，
        // 也就是实际能够生成object而的哪个class文件的名字，而不是bean的id名。
        SpringDao s1 = (SpringDao) ctx.getBean("sDao");
        SpringDao s2 = ctx.getBean("sDao", SpringDao.class);
        System.out.println(s1);
        System.out.println(s2);
        SpringService s3 = ctx.getBean(SpringServiceImpl.class);
        System.out.println(s3);
    }
}