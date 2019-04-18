import java.math.BigInteger;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger[] lis = new BigInteger[1123];
        BigInteger[] lt = new BigInteger[1123];
        BigInteger[] rt = new BigInteger[1123];
        int t = in.nextInt();
        for (int cs = 1; cs <= t; cs++) {
            BigInteger n = in.nextBigInteger();
            Map mp = new TreeMap<BigInteger, Character>();
            int len = in.nextInt();
            for (int i = 0; i < len; i++) {
                lis[i] = in.nextBigInteger();
            }
            int index = 0;
            for (int i = 0; i < len-1; i++) {
                if (!lis[i].equals(lis[i+1])) {
                    rt[i] = lis[i].gcd(lis[i+1]);
                    lt[i+1] = rt[i];
                    lt[i] = lis[i].divide(rt[i]);
                    index = i;
                    break;
                }
            }
            for (int i=index+1; i<len; i++) {
                lt[i] = rt[i-1];
                rt[i] = lis[i].divide(rt[i-1]);
            }
            for (int i=index-1; i>=0; i--) {
                rt[i] = lt[i+1];
                lt[i] = lis[i].divide(rt[i]);
            }
            StringBuilder ans = new StringBuilder();

            for (int i = 0; i < len; i++) {
                mp.put(lt[i], '0');
                mp.put(rt[i], '0');
            }
            Iterator<BigInteger> iter = mp.keySet().iterator();

            int cnt = 0;
//            System.out.println(mp.size());
            while (iter.hasNext()) {
                BigInteger key = iter.next();
                mp.put(key, (char)('A'+cnt));
                cnt++;
            }

            for (int i = 0; i < len; i++) {
                ans.append(mp.get(lt[i]));
            }
            ans.append(mp.get(rt[len-1]));
            System.out.println("Case #" + cs + ": " + ans);
        }
    }
}
