package com.kxfevr;

import java.io.File;

public class ChangeFileExtension {
    public static void main(String[] args) {
        // 待处理的文件夹路径
        String folderPath = "C:/your/folder/path";
        // 旧后缀名
        String oldExtension = ".heic";
        // 新后缀名
        String newExtension = ".jpg";
        changeExtensions(folderPath, oldExtension, newExtension);
    }

    public static void changeExtensions(String folderPath, String oldExtension, String newExtension) {
        File folder = new File(folderPath);
        // 判断文件夹是否存在且是一个文件夹
        if (folder.exists() && folder.isDirectory()) {
            File[] files = folder.listFiles();
            if (files!= null) {
                for (File file : files) {
                    if (file.isFile()) {
                        String fileName = file.getName();
                        if (fileName.endsWith(oldExtension)) {
                            // 构建新的文件名
                            String newFileName = fileName.substring(0, fileName.lastIndexOf(oldExtension)) + newExtension;
                            File newFile = new File(folder, newFileName);
                            // 重命名文件
                            if (file.renameTo(newFile)) {
                                System.out.println("已成功将 " + fileName + " 重命名为 " + newFileName);
                            } else {
                                System.out.println("重命名 " + fileName + " 失败");
                            }
                        }
                    }
                }
            }
        } else {
            System.out.println("指定的文件夹不存在或者不是一个文件夹");
        }
    }
}
