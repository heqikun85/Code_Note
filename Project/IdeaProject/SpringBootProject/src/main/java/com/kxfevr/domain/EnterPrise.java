package com.kxfevr.domain;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

import java.util.Arrays;

@Component // 配置为组件，能被SpringBoot读取
@ConfigurationProperties(prefix = "enterprise") // 注入属性名
public class EnterPrise {
    private String name;
    private int age;
    private String tel;
    private String[] subject;


    public EnterPrise() {
    }

    public EnterPrise(String name, int age, String tel, String[] subject) {
        this.name = name;
        this.age = age;
        this.tel = tel;
        this.subject = subject;
    }

    /**
     * 获取
     * @return name
     */
    public String getName() {
        return name;
    }

    /**
     * 设置
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * 获取
     * @return age
     */
    public int getAge() {
        return age;
    }

    /**
     * 设置
     * @param age
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     * 获取
     * @return tel
     */
    public String getTel() {
        return tel;
    }

    /**
     * 设置
     * @param tel
     */
    public void setTel(String tel) {
        this.tel = tel;
    }

    /**
     * 获取
     * @return subject
     */
    public String[] getSubject() {
        return subject;
    }

    /**
     * 设置
     * @param subject
     */
    public void setSubject(String[] subject) {
        this.subject = subject;
    }

    public String toString() {
        return "EnterPrise{" +
                "name = " + name + ", " +
                "age = " + age + ", " +
                "tel = " + tel + ", " +
                "subject = " + Arrays.toString(subject)  + "}";
    }
}
