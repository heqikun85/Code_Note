package com.kxfevr.controller;

import com.kxfevr.domain.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/users")
public class UserCtrl {

    @PostMapping
    public String save(@RequestBody User user) {
        System.out.println("user saving..." + user);
        return "{'module':'user save'}";
    }

    @DeleteMapping("/{id}")
    public String delete(@PathVariable Integer id) {
        System.out.println("user deleting..." + id);
        return "{'module':'user delete'}";
    }

    @PutMapping
    public String update(@RequestBody User user) {
        System.out.println("user updating..." + user);
        return "{'module':'user update'}";
    }

    @GetMapping("/{id}")
    public String search(@PathVariable Integer id) {
        System.out.println("user searching..." + id);
        return "{'module':'user get by ID'}";
    }

    @GetMapping
    public String getAll() {
        System.out.println("user all...");
        return "{'module':'user getAll'}";
    }

/*
    <!-- orignal method-->
    @RequestMapping("/save")
    @ResponseBody
    public String save(@RequestBody User user) {
        System.out.println("user saving..." + user);
        return "{'module':'user save'}";
    }

    @RequestMapping("/delete")
    @ResponseBody
    public String delete(@RequestBody Integer id) {
        System.out.println("user deleting..." + id);
        return "{'module':'user delete'}";
    }

    @RequestMapping("/update")
    @ResponseBody
    public String update(@RequestBody User user) {
        System.out.println("user updating..." + user);
        return "{'module':'user update'}";
    }

    @RequestMapping("/getById")
    @ResponseBody
    public String search(@RequestBody Integer id) {
        System.out.println("user searching..." + id);
        return "{'module':'user get by ID'}";
    }

    @RequestMapping("/getAll")
    @ResponseBody
    public String getAll() {
        System.out.println("user all...");
        return "{'module':'user getAll'}";
    }*/
}
