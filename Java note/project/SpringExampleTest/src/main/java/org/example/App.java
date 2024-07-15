package org.example;

import org.example.config.springconfig;
import org.example.dao.Impl.SpringDaoImpl;
import org.example.dao.SpringDao;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class App {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(springconfig.class);

        SpringDao s1 = ctx.getBean(SpringDaoImpl.class);

        s1.save();
    }
}
