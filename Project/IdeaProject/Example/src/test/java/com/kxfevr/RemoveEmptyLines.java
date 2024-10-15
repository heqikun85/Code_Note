package com.kxfevr;

import java.io.*;
import java.nio.file.*;
import java.util.List;
import java.util.stream.Collectors;

public class RemoveEmptyLines {

    public static void main(String[] args) {
        // 输入文件路径和输出文件路径
        String inputFilePath = "/Users/kevinhe/Desktop/1.txt";  // 源文件路径
        String outputFilePath = "/Users/kevinhe/Desktop/output.txt"; // 输出文件路径

        removeEmptyLines(inputFilePath, outputFilePath);
    }

    public static void removeEmptyLines(String inputFilePath, String outputFilePath) {
        try {
            // 读取文件
            List<String> lines = Files.readAllLines(Paths.get(inputFilePath));

            // 过滤掉空行并保留非空行
            List<String> nonEmptyLines = lines.stream()
                    .filter(line -> !line.trim().isEmpty())
                    .collect(Collectors.toList());

            // 写入到新的文件中
            Files.write(Paths.get(outputFilePath), nonEmptyLines);

            System.out.println("空行已移除，并保存到新文件：" + outputFilePath);

        } catch (IOException e) {
            System.err.println("文件处理时发生错误: " + e.getMessage());
        }
    }
}