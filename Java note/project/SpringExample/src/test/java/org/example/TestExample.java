package org.example;


import org.example.domain.User;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestExample {
    ClassPathXmlApplicationContext ioc;
    @BeforeEach
    public void before(){
        ioc = new ClassPathXmlApplicationContext("application.xml");
    }

    @Test
    public void test(){
        User user = (User) ioc.getBean("user");
        System.out.println(user);
    }
}