package com.kxfevr.domain;

public class User {
    private int id;
    private String name;
    private int age;
    private Addr addr;

    public User() {
    }

    public User(int id, String name, int age, Addr addr) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.addr = addr;
    }

    /**
     * 获取
     * @return id
     */
    public int getId() {
        return id;
    }

    /**
     * 设置
     * @param id
     */
    public void setId(int id) {
        this.id = id;
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
     * @return addr
     */
    public Addr getAddr() {
        return addr;
    }

    /**
     * 设置
     * @param addr
     */
    public void setAddr(Addr addr) {
        this.addr = addr;
    }

    public String toString() {
        return "User{id = " + id + ", name = " + name + ", age = " + age + ", addr = " + addr + "}";
    }
}
