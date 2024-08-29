package com.kxfevr.domain;

public class Addr {
    private String city;
    private String country;

    public Addr() {
    }

    public Addr(String city, String country) {
        this.city = city;
        this.country = country;
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
     * @return country
     */
    public String getCountry() {
        return country;
    }

    /**
     * 设置
     * @param country
     */
    public void setCountry(String country) {
        this.country = country;
    }

    public String toString() {
        return "Addr{city = " + city + ", country = " + country + "}";
    }
}
