package com.SpringMVCExample.domain;

public class Addr {
    private String city;
    private String street;
    private int num;

    public Addr() {
    }

    public Addr(String city, String street, int num) {
        this.city = city;
        this.street = street;
        this.num = num;
    }

    /**
     * 获取
     * @return city
     */
    public String getCity() {
        return city;
    }

    /**
     * 设置
     * @param city
     */
    public void setCity(String city) {
        this.city = city;
    }

    /**
     * 获取
     * @return street
     */
    public String getStreet() {
        return street;
    }

    /**
     * 设置
     * @param street
     */
    public void setStreet(String street) {
        this.street = street;
    }

    /**
     * 获取
     * @return num
     */
    public int getNum() {
        return num;
    }

    /**
     * 设置
     * @param num
     */
    public void setNum(int num) {
        this.num = num;
    }

    public String toString() {
        return "Addr{city = " + city + ", street = " + street + ", num = " + num + "}";
    }
}
