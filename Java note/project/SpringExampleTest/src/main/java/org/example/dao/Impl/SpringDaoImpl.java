package org.example.dao.Impl;

import org.example.dao.SpringDao;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Repository;


@Repository("sDao")
public class SpringDaoImpl implements SpringDao{
    @Value("${name}")
    private String name;

    public void save() {
        long startTime = System.currentTimeMillis();
        System.out.println(startTime);
        System.out.println("SpringDao ... save");
    }

    public void update() {
        System.out.println("SpringDao ... update");
    }

    public void delete(){
        System.out.println("SpringDao ... delete");
    }

    public int select(){
        System.out.println("select is running");
        return 100;
    }
}
