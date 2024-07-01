package Demo1;

public class ArrayUtil {
    // 私有化构造方法，为了不让外界构建它的对象。
    private ArrayUtil(){}

    public static String printArr(int[] arr){
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for(int i = 0; i < arr.length; i++){
            if(i == arr.length -1){
                sb.append(arr[i]);
            }else{
                sb.append(arr[i]).append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    public static double getAve(double[] arr){
        double sum = 0;
        for(int i = 0; i< arr.length; i++){
            sum = sum + arr[i];
        }
        return sum/arr.length;
    }
}
