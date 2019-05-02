// OCJP
// override println
// stringbuilder sort problem

import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {
    public static void main(String[] args) throws ParseException {
        String date = "2050-01-01 00:00:00";
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//24小时制
//		SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd hh-mm-ss");//12小时制
        long time1 = simpleDateFormat.parse(date).getTime();

        Scanner in = new Scanner (new BufferedInputStream(System.in));
        int t = in.nextInt();
        in.nextLine();

        for (int cs=1; cs<=t; cs++) {
            String s = in.nextLine();
            long time2 = simpleDateFormat.parse(s).getTime();
            time2 = time1-time2;
            time2/=1000;
            time2 %= 100;
            System.out.println(time2);
        }
    }
}
