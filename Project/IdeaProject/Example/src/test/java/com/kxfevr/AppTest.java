package com.kxfevr;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.io.File;

/**
 * Unit test for simple App.
 */
public class AppTest 
    extends TestCase
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public AppTest( String testName )
    {
        super( testName );
    }

    /**
     * @return the suite of tests being tested
     */
    public static Test suite()
    {
        return new TestSuite( AppTest.class );
    }

    /**
     * Rigourous Test :-)
     */
    public void testApp()
    {
        assertTrue( true );
    }

    public void test(){
    /*
        public File (String pathName)               根据文件路径创建对象
        public File (String parent, String child)   根据父路径名和子路径创建文件对象
        public File (File parent, String child)     根据父路径对应文件和子路径创建文件对象

        /Users/kevinhe/Desktop
    */
        // 1. 根据字符串表示的路径，变成File对象
        String str = "/Users/kevinhe/Desktop/a.txt";
        File f1 = new File(str);
        System.out.println(f1); // 打印文件地址

        // 2. 父级路径：/Users/kevinhe/Desktop/ 上面的路径中，这一段表示父级路径
        //    子路径：a.txt 为子路径
        String parent = "/Users/kevinhe/Desktop/";
        String child = "a.txt";
        File f2 = new File(parent,child);
        System.out.println(f2);

        File parent2 = new File("/Users/kevinhe/Desktop");
        String child2 = "a.txt";
        File f3 = new File(parent2, child2);
        System.out.println(f3);
    }
}


