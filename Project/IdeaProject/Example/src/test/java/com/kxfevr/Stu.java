package com.kxfevr;

public class Stu implements Comparable<Stu>{
    private String name;
    private int age;


    public Stu() {
    }

    public Stu(String name, int age) {
        this.name = name;
        this.age = age;
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



    public String toString() {
        return "Stu{name = " + name + ", age = " + age + "}";
    }

    @Override
    public int compareTo(Stu o) {
        int i = this.getAge() - o.getAge();

        return i == 0 ? this.getName().compareTo(o.getName()) : i;
    }
}
