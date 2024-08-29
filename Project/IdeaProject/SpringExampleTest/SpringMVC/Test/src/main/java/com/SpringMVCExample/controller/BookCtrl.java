package com.SpringMVCExample.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/book")
public class BookCtrl {
    @RequestMapping("/save")
    @ResponseBody
    public String save() {
        System.out.println("book saving...");
        return "{this is book saving}";
    }

}
