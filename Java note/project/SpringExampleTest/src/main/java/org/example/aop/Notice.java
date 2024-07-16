package org.example.aop;

import org.aspectj.lang.annotation.Pointcut;

public class Notice {
    @Pointcut // 该注释是在
    private void pt(){}

    void method(){
        //将共性功能单独提取出来，成为一个方法
        //所谓共性功能，就是原设计中的功能，在增强版中仍然需要的功能
        long startTime = System.currentTimeMillis();
        System.out.println(startTime);
    }
}
