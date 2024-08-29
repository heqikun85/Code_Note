package com.kxfevr;

import com.kxfevr.entity.Brand;
import com.kxfevr.mapper.BrandMapper;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Array;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class MyBatisTest {
    @Test
    public void testDelete2() throws IOException {
        int[] id = {12,13,14};

        //1.加载mybatis的核心配置文件，获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SQLSession对象，用它来执行SQL
        //SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true);

        //3.执行sql语句，传入xml里的id，namespace作为标识，id作为索引
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        brandMapper.delete2(id);

        //4.释放资源
        //sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void testDelete() throws IOException {
        int id = 6;

        //1.加载mybatis的核心配置文件，获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SQLSession对象，用它来执行SQL
        //SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true);

        //3.执行sql语句，传入xml里的id，namespace作为标识，id作为索引
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        brandMapper.delete(id);

        //4.释放资源
        //sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void testUpdate() throws IOException {
        int id = 6;
        String company = "波导手机";
        String brand_name = "波导";
        String description = "hello, MOTO, 摩托罗拉";

        Brand brand = new Brand();
        brand.setCompanyName(company);
        brand.setBrandName(brand_name);
        brand.setStatus(1);
        brand.setDescription(description);
        brand.setOrdered(100);
        brand.setId(id);

        //1.加载mybatis的核心配置文件，获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SQLSession对象，用它来执行SQL
        //SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true);

        //3.执行sql语句，传入xml里的id，namespace作为标识，id作为索引
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        brandMapper.update(brand);
        
        System.out.println(id);

        //4.释放资源
        //sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void testADD2() throws IOException {
        Brand brand = new Brand();
        brand.setCompanyName("摩托罗拉");
        brand.setBrandName("MOTO");
        brand.setStatus(1);
        brand.setDescription("Hello MOTO");
        brand.setOrdered(10000);

        //1.加载mybatis的核心配置文件，获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SQLSession对象，用它来执行SQL
        //SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true);

        //3.执行sql语句，传入xml里的id，namespace作为标识，id作为索引
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        brandMapper.add2(brand);
        Integer id = brand.getId();
        System.out.println(id);

        //4.释放资源
        //sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void testADD() throws IOException {
        String companyName = "诺基亚通讯科技";
        String brandName = "Nokia";
        int status = 1;
        String description = "与世界链接";
        int ordered= 10000;

        //1.加载mybatis的核心配置文件，获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SQLSession对象，用它来执行SQL
        //SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true);

        //3.执行sql语句，传入xml里的id，namespace作为标识，id作为索引
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        Map map = new HashMap();
        map.put("status", status);
        map.put("companyName", companyName);
        map.put("brandName", brandName);
        map.put("description", description);
        map.put("ordered", ordered);

        brandMapper.add(map);

        System.out.println();

        //4.释放资源
        //sqlSession.commit();
        sqlSession.close();
    }

    @Test
    public void testSearch() throws IOException {
        //1.加载mybatis的核心配置文件，获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SQLSession对象，用它来执行SQL
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.执行sql语句，传入xml里的id，namespace作为标识，id作为索引
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);
        List<Brand> brands = brandMapper.selectAll();
        Brand brand = brandMapper.selectById(2);

        String companyName = "波导";
        String brandName = "华为";
        int status = 1;

        companyName = "%" + companyName + "%";
        brandName = "%" + brandName + "%";

        Map map = new HashMap();
        map.put("status", status);
        map.put("companyName", companyName);
        map.put("brandName", brandName);

        List<Brand> lBrand = brandMapper.selectByCondition(map);

        System.out.println(lBrand);

        //4.释放资源
        sqlSession.close();
    }
}

