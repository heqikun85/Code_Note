import java.util.Date;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;

public class Main {
    public static void main(String[] args) {
        long stamp = System.currentTimeMillis();
        Date today = Utils.getToday();

        // 获取今天开始时间的LocalDateTime
        LocalDateTime startOfDay = today.toInstant().atZone(ZoneId.systemDefault()).toLocalDateTime();
        // 获取当前时间的LocalDateTime
        LocalDateTime now = LocalDateTime.now();

        // 计算从今天开始时间到当前时间的分钟数
        long mins = ChronoUnit.MINUTES.between(startOfDay, now);

        // 如果当前时间的秒数不为0，则增加一分钟
        if (now.getSecond() != 0) {
            mins += 1;
        }

        System.out.println(mins);
    }

}