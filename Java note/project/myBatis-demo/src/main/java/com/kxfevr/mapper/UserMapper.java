package com.kxfevr.mapper;

import com.kxfevr.entity.User;

import java.util.List;

public interface UserMapper {
    List<User> selectALL();

    User selectById(int id);
}
