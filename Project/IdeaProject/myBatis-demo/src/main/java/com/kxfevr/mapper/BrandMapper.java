package com.kxfevr.mapper;

import com.kxfevr.entity.Brand;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import java.util.Map;

public interface BrandMapper {
    List<Brand> selectAll();
    Brand selectById(int id);
    List<Brand> selectByCondition1(@Param("status")int status, @Param("companyName") String companyName, @Param("brandName") String brandName);
    List<Brand> selectByCondition2(Brand brand);
    List<Brand> selectByCondition(Map map);
    void add(Map map);
    void add2(Brand brand);
    void update(Brand brand);
    void delete(int id);
    void delete2(@Param("ids") int[] ids);
}
