package com.kxfevr;

import com.kxfevr.service.BookSer;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class ApplicationTest {
	@Autowired
	private BookSer boo;

	@Test
	void context(){
		boo.save();
	}

}