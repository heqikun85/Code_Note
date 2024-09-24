package com.kxfevr;

import java.util.Objects;

public class Student implements Comparable<Student> {
    // 属性：姓名，年龄，性别
    private String name;
    private int age;
    private String gender;
    public static String teacherName;

    public Student(){

    }

    public Student(String name, int age, String gender){
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void study(){
        System.out.println(name + "正在学习");
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return age == student.age && Objects.equals(name, student.name) && Objects.equals(gender, student.gender);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age, gender);
    }

    public void show(){
        System.out.println(name +", " + age + ", " + gender + ", " + teacherName);
    }



    @Override
    public int compareTo(Student o) {
        return this.getAge() - o.getAge();
    }
}
