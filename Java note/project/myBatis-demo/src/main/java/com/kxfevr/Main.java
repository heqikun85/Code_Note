package com.kxfevr;

import com.kxfevr.entity.User;
import com.kxfevr.mapper.UserMapper;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        //1.加载mybatis的核心配置文件，获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SQLSession对象，用它来执行SQL
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.执行sql语句，传入xml里的id，namespace作为标识，id作为索引
        UserMapper userM = sqlSession.getMapper(UserMapper.class);
        List<User> users = userM.selectALL();

        System.out.println(users);

        //4.释放资源
        sqlSession.close();

    }
}