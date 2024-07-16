package org.example.aop;

public class Notice {
    @Pointcut
    private void pt(){}

    void method(){
        //将共性功能单独提取出来，成为一个方法
        //所谓共性功能，就是原设计中的功能，在增强版中仍然需要的功能
        long startTime = System.currentTimeMillis();
        System.out.println(startTime);
    }
}
