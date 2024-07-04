package Demo1;

public class Test1 {
    public static void main(String[] args) {
        int[] rabbit = new int[12];
        rabbit[0] = 1;
        rabbit[1] = 1;

        System.out.println(getSum(12));
    }

    public static int getSum(int month) {
        if (month == 1 || month == 2) {
            return 1;
        } else {
            return getSum(month - 1) + getSum(month - 2);
        }
    }
}