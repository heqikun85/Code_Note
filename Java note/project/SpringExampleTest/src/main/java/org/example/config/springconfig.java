package org.example.config;

import org.springframework.context.annotation.*;

@Configuration
@Import(jdbcConfig.class)
@ComponentScan("org.example")
@PropertySource("jdbc.properties")
@EnableAspectJAutoProxy

public class springconfig {
}
