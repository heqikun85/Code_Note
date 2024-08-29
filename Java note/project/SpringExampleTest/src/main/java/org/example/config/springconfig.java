package org.example.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;
import org.springframework.context.annotation.PropertySource;

@Configuration
@Import(jdbcConfig.class)
@ComponentScan("org.example")
@PropertySource("jdbc.properties")

public class springconfig {
}
