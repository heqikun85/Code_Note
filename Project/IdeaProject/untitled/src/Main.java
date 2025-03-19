import java.io.File;

public class Main {
    public static void main(String[] args) {
        // 指定文件夹路径
        String folderPath = "C:\\Users\\heqik\\Music\\Music\\日韩流\\米津玄師";

        // 创建File对象指向文件夹
        File folder = new File(folderPath);

        // 检查路径是否存在且是一个文件夹
        if (folder.exists() && folder.isDirectory()) {
            // 获取文件夹内的所有文件
            File[] files = folder.listFiles();

            // 遍历文件
            if (files != null) {
                for (File file : files) {
                    // 只处理文件（忽略文件夹）
                    if (file.isFile()) {
                        // 获取文件名
                        String fileName = file.getName();

                        // 查找第一个空格的位置
                        int firstSpaceIndex = fileName.indexOf(" ");

                        // 如果文件名中包含空格
                        if (firstSpaceIndex != -1 && firstSpaceIndex > 0) {
                            // 获取空格前一个字符
                            char charBeforeSpace = fileName.charAt(firstSpaceIndex - 1);

                            // 检查字符是否是英文字母
                            if (!isEnglishLetter(charBeforeSpace)) {
                                // 删除第一个空格及其前面的部分
                                String newFileName = fileName.substring(firstSpaceIndex + 1);

                                // 构建新的文件路径
                                File newFile = new File(folderPath, newFileName);

                                // 重命名文件
                                if (file.renameTo(newFile)) {
                                    System.out.println("Renamed: \"" + fileName + "\" -> \"" + newFileName + "\"");
                                } else {
                                    System.out.println("Failed to rename: \"" + fileName + "\"");
                                }
                            }
                        }
                    }
                }
            }
        } else {
            System.out.println("Invalid folder path: " + folderPath);
        }
    }

    // 检查字符是否是英文字母
    private static boolean isEnglishLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
}