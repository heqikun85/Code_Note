package org.example.aop;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

// 加载入Spring框架，让Spring能读取到
@Component
// 在Spring中注释为AOP
@Aspect
//创建一个和dao，service平级的aop层，并创建一个通知类
public class Notice {
    // 该注释是在org.aspectj坐标依赖下的
    // Pointcut是切入点的注释，execution是执行监视器，参数是监听的方法的完整地址
    @Pointcut("execution(void org.example.dao.SpringDao.update())")
    // 给切入点做一个本地副本，作为接口让其他方法切入
    private void pt(){};

    @Pointcut("execution(int org..*Impl.select())")
    private void pt2(){};

    // 刚刚的是程序切口接入点，当程序监听到切入点程序运行时，以下方法先运行
    @Before("pt()")
    void before(){
        System.out.println("before pointcut");
    }

    @After("pt()")
    void after(){
        System.out.println("after pointcut");
    }

    @Around("pt()")
    void around(ProceedingJoinPoint pj) throws Throwable {
        System.out.println("around before pointcut");
        pj.proceed();
        System.out.println("around after pointcut");
    }

    @Around("pt2()")
    Object around2(ProceedingJoinPoint pj) throws Throwable {
        System.out.println("around before pointcut");
        Integer proceed = (Integer) pj.proceed();
        System.out.println("around after pointcut");
        return proceed + 20;
    }
    //@AfterReturning("pt()")
    void afterReturn(){
        System.out.println("after return pointcut");
    }

    //@AfterThrowing("pt()")
    void afterThrow(){
        System.out.println("after throw pointcut");
    }

}
