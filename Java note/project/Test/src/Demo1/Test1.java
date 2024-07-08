package Demo1;

public class Test1 {
    public static void main(String[] args) {
        //可变参数：function的参数个数是可以变化的。
        //格式：function_name(type...name){}
        System.out.println(getSum(5,19,30,44));
    }

    private static int getSum(int...args) {
        int sum = 0;
        for (int arg : args) {
            sum += arg;
        }
        return sum;
    }
}
 