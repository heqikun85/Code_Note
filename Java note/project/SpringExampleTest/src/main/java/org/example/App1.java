package org.example;

import org.example.config.springconfig;
import org.example.dao.Impl.SpringDaoImpl;
import org.example.dao.SpringDao;
import org.example.service.Impl.SpringServiceImpl;
import org.example.service.SpringService;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import javax.sql.DataSource;

public class App1 {
    public static void main(String[] args) {
            AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(springconfig.class);
            DataSource bean = ctx.getBean(DataSource.class);
            System.out.println(bean);
            SpringDao sd = ctx.getBean(SpringDaoImpl.class);
            SpringServiceImpl bean1 = ctx.getBean(SpringServiceImpl.class);
            sd.save();
            bean1.save();
    }
}
