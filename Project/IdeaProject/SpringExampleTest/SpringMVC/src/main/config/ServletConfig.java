package com.SpringMVCExample.config;

import org.springframework.web.context.WebApplicationContext;
import org.springframework.web.context.support.AnnotationConfigWebApplicationContext;
import org.springframework.web.servlet.support.AbstractDispatcherServletInitializer;

// 定义一个Servlet容器启动的配置类。并加载Spring的配置
public class ServletConfig extends AbstractDispatcherServletInitializer {
    // 加载SpringMVC容器配置的
    @Override
    protected WebApplicationContext createServletApplicationContext() {
        // 专属于web环境的object Type
        AnnotationConfigWebApplicationContext ctx = new AnnotationConfigWebApplicationContext();
        // 关联SpringMVC的配置
        ctx.register(SpringMVCconfig.class);
        return ctx;
    }

    // 设置哪些请求归SpringMVC处理的
    @Override
    protected String[] getServletMappings() {
        //这段标示，所有请求都归Spring MVC处理
        return new String[]{"/"};
    }

    // 加载Spring容器的配置
    @Override
    protected WebApplicationContext createRootApplicationContext() {
        return null;
    }
}
