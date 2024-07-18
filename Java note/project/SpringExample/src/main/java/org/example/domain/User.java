package org.example.domain;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class User {
    // 使用Value注入信息，注意：一般都是应用外部导入的数据。
    // @Value(${}) / @Value(#{})
    @Value("Kevin He")
    private String name;
    @Value("#{role.age}")
    private int age;
    @Value("${mySql.address}")
    private String address;

    public User() {
    }

    public User(String name) {
        this.name = name;
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
    public String toString() {
        return "User{name = " + name + " age = " + age + " address = " + address + "}";
    }
}
