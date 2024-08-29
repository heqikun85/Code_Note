package com.kxfevr.service.Impl;

import com.kxfevr.service.BookSer;
import org.springframework.stereotype.Service;

@Service
public class BookSerImpl implements BookSer {

    @Override
    public void save() {
        System.out.println("book service is running...");
    }
}
