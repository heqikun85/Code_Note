package Demo1;

import javax.swing.*;
import javax.swing.plaf.multi.MultiLookAndFeel;

public class Test1 {
    public static void main(String[] args) {
        JFrame jFrame = new JFrame();
        jFrame.setSize(603,680);
        jFrame.setTitle("监听演示");
        jFrame.setAlwaysOnTop(true);
        jFrame.setLocationRelativeTo(null);
        jFrame.setDefaultCloseOperation(3);
        jFrame.setLayout(null);

        //创建按钮对象
        JButton jtb = new JButton("点我呀");
        jtb.setBounds(0,0,100,50);
        //创建按键监听，jtb组件对象，表示给哪个组件添加事件。
        //addActionListener: 添加事件监听，参数（鼠标左键点击，空格）

        jFrame.getContentPane().add(jtb);

        jFrame.setVisible(true);
    }
}
