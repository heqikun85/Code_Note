package com.kxfevr.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.kxfevr.pojo.User1;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface User1Mapper extends BaseMapper<User1> {
    void saveUser(User1 user);
    void deleteuser(Long id);
    void updateUser(User1 user);
    User1 queryUserById(@Param("id")Long id);
    List<User1> queryuserByIds(@Param("ids") List<Long> ids)

}
