package com.kxfevr.movespace;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

@SpringBootTest
class MoveSpaceApplicationTests {

    @Test
    public static void main(String[] args) {
        // 输入文件路径
        String inputFilePath = "/Users/kevinhe/IdeaProjects/2.txt";
        // PDF文件保存路径
        String outputDirectory = "/Users/kevinhe/IdeaProjects/output_pdfs/";

        pdfServiceImpl p = new pdfServiceImpl();

        // 创建输出目录
        new File(outputDirectory).mkdirs();

        try (BufferedReader br = Files.newBufferedReader(Paths.get(inputFilePath))) {
            String fileName;
            while ((fileName = br.readLine()) != null) {
                String pdfFilePath = outputDirectory + fileName + ".pdf";
                p.creat(pdfFilePath); // 创建空的PDF文件
                p.addTextToPDF(pdfFilePath, fileName); // 将文件名作为内容添加到PDF中
            }
            System.out.println("文件处理完成，结果已保存");
        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("发生错误: " + e.getMessage());
        }
    }
}
