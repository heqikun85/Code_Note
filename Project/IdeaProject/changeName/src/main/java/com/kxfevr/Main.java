package com.kxfevr;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        // 输入文件和输出文件的路径
        String inputFilePath = "/Users/kevinhe/Desktop/学习/Code_Note/Project/IdeaProject/1.txt";
        String outputFilePath = "/Users/kevinhe/Desktop/学习/Code_Note/Project/IdeaProject/output.txt";

        try (
                BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
                BufferedWriter writer = new BufferedWriter(new FileWriter(outputFilePath))
        ) {
            String line;
            while ((line = reader.readLine()) != null) {
                // 分割行并替换中间的部分
                String[] parts = line.split("\\.");
                if (parts.length >= 3) {
                    String tableName = parts[2];  // 获取第三部分，也就是 . 之后的表名
                    String outputLine = "drop trigger trg_Audit_" + tableName + ";";
                    writer.write(outputLine);
                    writer.newLine();
                }
            }
            System.out.println("脚本生成成功！");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

