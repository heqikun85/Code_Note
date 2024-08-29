package com.kxfevr.pojo;

public class User {
    private Long id;

    private String username;

    private String password;

    private String phone;

    private String info;

    private Integer status;

    private Integer balance;

    private String createTime;

    private String updateTime;

    public User() {
    }

    public User(Long id, String username, String password, String phone, String info, Integer status, Integer balance, String createTime, String updateTime) {
        this.id = id;
        this.username = username;
        this.password = password;
        this.phone = phone;
        this.info = info;
        this.status = status;
        this.balance = balance;
        this.createTime = createTime;
        this.updateTime = updateTime;
    }

    /**
     * 获取
     * @return id
     */
    public Long getId() {
        return id;
    }

    /**
     * 设置
     * @param id
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     * 获取
     * @return username
     */
    public String getUsername() {
        return username;
    }

    /**
     * 设置
     * @param username
     */
    public void setUsername(String username) {
        this.username = username;
    }

    /**
     * 获取
     * @return password
     */
    public String getPassword() {
        return password;
    }

    /**
     * 设置
     * @param password
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * 获取
     * @return phone
     */
    public String getPhone() {
        return phone;
    }

    /**
     * 设置
     * @param phone
     */
    public void setPhone(String phone) {
        this.phone = phone;
    }

    /**
     * 获取
     * @return info
     */
    public String getInfo() {
        return info;
    }

    /**
     * 设置
     * @param info
     */
    public void setInfo(String info) {
        this.info = info;
    }

    /**
     * 获取
     * @return status
     */
    public Integer getStatus() {
        return status;
    }

    /**
     * 设置
     * @param status
     */
    public void setStatus(Integer status) {
        this.status = status;
    }

    /**
     * 获取
     * @return balance
     */
    public Integer getBalance() {
        return balance;
    }

    /**
     * 设置
     * @param balance
     */
    public void setBalance(Integer balance) {
        this.balance = balance;
    }

    /**
     * 获取
     * @return createTime
     */
    public String getCreateTime() {
        return createTime;
    }

    /**
     * 设置
     * @param createTime
     */
    public void setCreateTime(String createTime) {
        this.createTime = createTime;
    }

    /**
     * 获取
     * @return updateTime
     */
    public String getUpdateTime() {
        return updateTime;
    }

    /**
     * 设置
     * @param updateTime
     */
    public void setUpdateTime(String updateTime) {
        this.updateTime = updateTime;
    }

    public String toString() {
        return "User{id = " + id + ", username = " + username + ", password = " + password + ", phone = " + phone + ", info = " + info + ", status = " + status + ", balance = " + balance + ", createTime = " + createTime + ", updateTime = " + updateTime + "}";
    }
}
