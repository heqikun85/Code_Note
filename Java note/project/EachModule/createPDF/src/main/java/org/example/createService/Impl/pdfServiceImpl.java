package org.example.createService.Impl;

import java.io.*;

import org.apache.pdfbox.pdmodel.font.PDType0Font;
import org.example.createService.pdfService;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.PDPageContentStream;
import org.apache.pdfbox.pdmodel.font.PDType1Font;

public class pdfServiceImpl implements pdfService {
    @Override
    public void creat(String filePath) {
        try (PDDocument document = new PDDocument()) {
            PDPage page = new PDPage();
            document.addPage(page);
            document.save(filePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    // 添加文本内容到PDF文件
    public void addTextToPDF(String pdfFilePath, String textContent) {
        // 使用PDF库将文本内容添加到PDF文件中
        // Apache PDFBox
        try (PDDocument document = PDDocument.load(new File(pdfFilePath))) {
            PDPage page = document.getPage(0);
            PDPageContentStream contentStream = new PDPageContentStream(document, page);

            // 加载系统中的常见中文字体，比如 SimSun
            PDType0Font font = PDType0Font.load(document, new File("/Users/kevinhe/IdeaProjects/EachModule/font/NotoSansSC-Regular.ttf"));

            contentStream.setFont(font, 12);
            contentStream.beginText();
            contentStream.newLineAtOffset(100, 700);
            contentStream.showText(textContent);
            contentStream.endText();
            contentStream.close();
            document.save(pdfFilePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
