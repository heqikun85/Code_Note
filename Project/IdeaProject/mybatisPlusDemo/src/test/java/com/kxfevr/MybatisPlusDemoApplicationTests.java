package com.kxfevr;

import com.kxfevr.mapper.UserMapper;
import com.kxfevr.pojo.User;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import java.time.LocalDateTime;
import java.util.List;

@SpringBootTest
class MybatisPlusDemoApplicationTests {
    @Autowired
    private UserMapper userMapper;

    @Test
    void tenInsert(){
        User user = new User();
        user.setId(6L);
        user.setUsername("Lucia");
        user.setPassword("123");
        user.setPhone("18688990012");
        user.setBalance(200);
        user.setInfo("{\"age\": 24,\"intro\":\"英文老师\",\"gender\": \"female\"}");
        user.setCreateTime(LocalDateTime.now());
        user.setUpdateTime(LocalDateTime.now());userMapper.insert(user);
    }

    @Test
    void testSelectById() {
        User user = userMapper.selectById(5L);
        System.out.println("user = " + user);
    }

    @Test
    void testQueryByIds(){
        List<User> users = userMapper.selectBatchIds(List.of(1L, 2L, 3L, 4L));
        users.forEach(System.out::println);
    }

    @Test
    void testUpdateById() {
        User user = new User();
        user.setId(5L);
        user.setBalance(20000);
        userMapper.updateById(user);
    }

    @Test
    void testDeleteUser(){
        userMapper.deleteById(6L);
    }
}
