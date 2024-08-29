package org.example;

import com.itextpdf.text.BaseColor;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.Font;
import com.itextpdf.text.pdf.BaseFont;
import com.itextpdf.text.pdf.PdfContentByte;
import com.itextpdf.text.pdf.PdfGState;
import com.itextpdf.text.pdf.PdfReader;
import com.itextpdf.text.pdf.PdfStamper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class PdfWatermark {

    private static final Logger log = LoggerFactory.getLogger(PdfWatermark.class);

    public static void main(String[] args) {
        String srcFilePath = "/Users/kevinhe/B02-46%-散装-标签(企标特二级品).pdf";
        File destFile = new File("/Users/kevinhe/output.pdf");
        String foot = "2024/07/11";  // 生产日期

        PdfWatermark watermark = new PdfWatermark();
        boolean result = watermark.addWaterMark(srcFilePath, destFile, foot);
        if (result) {
            log.info("Watermark added successfully.");
        } else {
            log.error("Failed to add watermark.");
        }
    }

    private boolean addWaterMark(String srcFilePath, File destFile, String foot) {
        PdfReader reader;
        try {
            reader = new PdfReader(srcFilePath);
            return addWaterMark(reader, destFile, foot);
        } catch (IOException e) {
            log.error("PDF error", e);
            return false;
        }
    }

    private boolean addWaterMark(PdfReader reader, File destFile, String foot) {
        PdfStamper stamper = null;
        try {
            stamper = new PdfStamper(reader, new FileOutputStream(destFile));
            PdfGState gs = new PdfGState();

            // 使用Helvetica字体
            BaseFont baseFont = BaseFont.createFont("C:/Windows/Fonts/SIMSUN.TTC,1", BaseFont.IDENTITY_H, BaseFont.EMBEDDED);
            Font font = new Font(baseFont, 10);
            font.setStyle(Font.BOLD);

            // 设置透明度
            gs.setFillOpacity(0.3f);
            PdfGState gs2 = new PdfGState();
            gs2.setFillOpacity(1f);

            int total = reader.getNumberOfPages();
            PdfContentByte content;
            for (int i = 1; i <= total; i++) {
                content = stamper.getOverContent(i);
                content.saveState();
                content.setGState(gs2);
                content.beginText();
                content.setColorFill(BaseColor.BLACK);
                content.setTextMatrix(180, 376);  // 根据实际位置调整坐标
                // 输出的text
                content.setFontAndSize(font.getBaseFont(), 12);
                content.showText(foot);
                content.endText();
                content.restoreState();
            }
            stamper.close();
            return true;
        } catch (IOException | DocumentException e) {
            log.error("PDF error", e);
            return false;
        } finally {
            if (stamper != null) {
                try {
                    stamper.close();
                } catch (DocumentException | IOException e) {
                    log.error("Error closing stamper", e);
                }
            }
        }
    }
}