package com.SpringMVCExample.controller;

import org.springframework.stereotype.Controller;
import com.SpringMVCExample.domain.User;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.List;

@Controller
// @RequestMapping("/user")
public class UserCtrl {

/*
    @RequestMapping("/listParam")
    @ResponseBody
    public String listParam(@RequestParam List<String> likes){
        System.out.println("Array List Parameter transfer likes => " + likes);
        return "{'module':''list parameter'}";
    }

    //集合参数：json格式
    @RequestMapping("/listParamForJson")
    @ResponseBody
    public String listParamForJson(@RequestBody List<String> likes) {
        System.out.println("list common(json)参数传递 list ==>" + likes);
        return "{'module':'list common for json param'}";
    }

    //P0J0参数:json格式
    @RequestMapping("/pojoParamForJson")
    @ResponseBody
    public String pojoParamForJson(@RequestBody User user) {
        System.out.println("pojo(json)参数传递 user ==>" + user);
        return "{'module':'pojo for json param'}";
    }

    //集合参数:json格式
    @RequestMapping("/listPojoParamForJson")
    @ResponseBody
    public String listPojoParamForJson(@RequestBody List<User> list) {
        System.out.println("list pojo(json)参数传递 list ==>" + list);
        return "{'module':'list pojo for json param'}";
    }


    // 设置当前方法的访问路径
    @RequestMapping("/save")
    // 设置当前操作的返回值
    @ResponseBody
    public String save() {
        System.out.println("mvc saving ...");
        return "{'info':'this is a spring mvc test'}";
    }

    @RequestMapping("/delete")
    // 设置当前操作的返回值
    @ResponseBody
    public String delete() {
        System.out.println("mvc delete...");
        return "{'info':'this is a delete request'}";
    }

    @RequestMapping("/commonParam")
    @ResponseBody
    public String commonParam(String name, int age) {
        System.out.println("common Param transfer => " + name);
        System.out.println("common Param transfer => " + age);
        return "{'info':'this is a common param request'}";
    }

    @RequestMapping("/cParamDiffName")
    @ResponseBody
    public String cParamDiffName(@RequestParam("name") String userName, int age) {
        System.out.println(userName);
        System.out.println(age);
        return "{'module' : 'common param diff'}";
    }

    @RequestMapping("/pojo")
    @ResponseBody
    public String pojo(User user) {
        System.out.println(user);
        return "{'module' : 'pojo parameter'}";
    }
*/

    // 响应页面，跳转页面
    @RequestMapping("/toJumpPage")
    public String toJumpPage() {
        System.out.println("跳转页面");
        return "index";
    }

    // 响应文本数据
    @RequestMapping("toText")
    // 如果返回的是页面，则在webConfig文件里配置，在return里返回页面文件名
    // 返回页面不需要@ResponseBody，返回字符串需要
    @ResponseBody
    public String toText() {
        System.out.println("return the text data");
        return "response text";
    }

    // 响应pojo object
    @RequestMapping("toJsonPojo")
    // 响应的是json object 也需要@ResponseBody
    @ResponseBody
    public User toJsonPojo() {
        System.out.println("return the Json pojo data");
        User user = new User();
        user.setName("Kevin He");
        user.setAge(38);
        return user;
    }
}
