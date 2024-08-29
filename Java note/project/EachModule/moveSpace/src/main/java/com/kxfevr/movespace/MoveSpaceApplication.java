package com.kxfevr.movespace;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MoveSpaceApplication {
    public static void main(String[] args) {
        // 输入和输出文件路径
        String inputFile = "/Users/kevinhe/IdeaProjects/1.txt";
        String outputFile = "/Users/kevinhe/IdeaProjects/2.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
             BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {

            String line;
            while ((line = reader.readLine()) != null) {
                // 去除空格
                String trimmedLine = line.replaceAll("\\s+", "");
                writer.write(trimmedLine);
                writer.newLine();
            }

            System.out.println("文件处理完成，结果已保存至：" + outputFile);

        } catch (IOException e) {
            System.err.println("发生错误: " + e.getMessage());
        }
    }
}
