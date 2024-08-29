package com.SpringMVCExample.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

// 创建SpringMVC的配置，加载UserController Bean
@Configuration
@ComponentScan("com.SpringMVCExample.controller")
public class SpringMVCconfig {

}
