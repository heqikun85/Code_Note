package com.kxfevr.movespace;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MoveChar {
    public static void main(String[] args) {
        // 输入和输出文件的路径
        String inputFile = "/Users/kevinhe/IdeaProjects/orderid.txt";
        String outputFile = "/Users/kevinhe/IdeaProjects/orderidOut.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
             BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {

            String line;
            while ((line = reader.readLine()) != null) {
                // 检查并去除每行开头的两个英文字母
                if (line.length() >= 2 && line.substring(0, 2).matches("[a-zA-Z]{2}")) {
                    line = line.substring(2);
                }
                writer.write(line);
                writer.newLine();
            }

            System.out.println("文件处理完成，结果已保存至：" + outputFile);

        } catch (IOException e) {
            System.err.println("发生错误: " + e.getMessage());
        }
    }
}