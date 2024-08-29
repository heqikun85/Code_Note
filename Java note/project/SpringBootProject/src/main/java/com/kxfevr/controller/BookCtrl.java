package com.kxfevr.controller;

import com.kxfevr.domain.EnterPrise;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.env.Environment;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/books")
public class BookCtrl {
    @Value("${lesson}")
    private String lesson;
    @Value("${server.port}")
    private String port;
    @Value("${enterprise.subject.0}")
    private String sub;

    @Autowired
    private Environment env;

    @Autowired
    private EnterPrise enter;

    @GetMapping("/{id}")
    public String getById(@PathVariable Integer id){
        System.out.println("port ==> "+ port);
        System.out.println("-------");
        System.out.println(env.getProperty("enterprise.name"));
        System.out.println("-------");
        System.out.println(enter);
        return lesson;
    }
}
