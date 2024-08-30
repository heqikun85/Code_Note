package com.kxfevr;

import com.kxfevr.mapper.User1Mapper;
import com.kxfevr.pojo.User1;
import org.junit.jupiter.api.Test;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.time.LocalDateTime;
import java.util.List;

@MapperScan("com.kxfevr.mapper")
@SpringBootApplication
public class MyBatisPlusTest {
    @Autowired
    private User1Mapper user1Mapper;

    @Test
    void tenInsert(){
        User1 user = new User1();
        user.setId(5L);
        user.setUsername("Lucy");
        user.setPassword("123");
        user.setPhone("18688990011");
        user.setBalance(200);
        user.setInfo("{\"age\": 24,\"intro\":\"英文老师\",\"gender\": \"female\"}");
        user.setCreateTime(LocalDateTime.now());
        user.setUpdateTime(LocalDateTime.now());user1Mapper.saveUser(user);
    }

    @Test
    void testSelectById() {
        User1 user = user1Mapper.queryUserById(5L);
        System.out.println("user = " + user);
    }

        @Test
    void testQueryByIds(){
        List<User1> users = user1Mapper.queryUserByIds(List.of(1L, 2L, 3L, 4L));
        users.forEach(System.out::println);
    }

    @Test
    void testUpdateById() {
        User1 user = new User1();
        user.setId(5L);
        user.setBalance(20000);
        user1Mapper.updateUser(user);
    }

    @Test
    void testDeleteUser(){
        user1Mapper.deleteUser(5L);
    }

}
