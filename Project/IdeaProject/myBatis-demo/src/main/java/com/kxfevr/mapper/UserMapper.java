package com.kxfevr.mapper;

import com.kxfevr.entity.User;
import org.apache.ibatis.annotations.Select;

import java.util.List;

public interface UserMapper {
    @Select("select * from tb_user")
    List<User> selectALL();

    @Select("select * from tb_user where id = #{id}")
    User selectById(int id);
}
