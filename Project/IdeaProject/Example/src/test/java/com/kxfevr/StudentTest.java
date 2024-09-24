package Demo1;
public class StudentTest {
    public static void main(String[] args){
        // 创建一个学生对象
        Student s1 = new Student();
        s1.setName("Kevin He");
        s1.setAge(38);
        s1.setGender("male");
        // s1.teacherName = "Evan Quan";
        Student.teacherName = "Evan Quan"; // 因为该属性是public的，所以不用使用方法赋值，可以直接赋值

        s1.study();
        s1.show();

        Student s2 = new Student();
        s2.setName("Angela xu");
        s2.setAge(38);
        s2.setGender("female");

        s2.show();
    }
}
