package org.example.service.Impl;

import org.example.dao.SpringDao;
import org.example.service.SpringService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Service;

@Service
public class SpringServiceImpl implements SpringService {
    @Autowired
    @Qualifier("sDao")
    private SpringDao springDao;

    @Override
    public void save(){
        System.out.println("this is SpringSerivce");
        springDao.save();
    };
}
