package com.kxfevr;

import java.util.ArrayList;
import java.util.Collections;

public class Test1 {
    public static void main(String[] args) {
        ArrayList<String> s = new ArrayList<>();
        Collections.addAll(s,"zhang san", "li si", "wang wu", "zhang liu", "zhang wu ji", "zhao ming", "zhang san feng");

        // 仅遍历并显示key
        long count = s.stream().count();
        System.out.println(count);

        //

    }
}
