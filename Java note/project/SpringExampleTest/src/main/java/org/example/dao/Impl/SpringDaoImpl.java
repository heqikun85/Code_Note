package org.example.dao.Impl;

import org.example.dao.SpringDao;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Repository;


@Repository("sDao")
public class SpringDaoImpl implements SpringDao{
    @Value("${name}")
    private String name;

    @Override
    public void save() {
        System.out.println("this is SpringDao ... " + name);
    }
}
