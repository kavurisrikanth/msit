import java.util.*;

public class Solution {
    public static void main(String[] args) {
        int num = 0, ans_one = 0, ans_two = 0, i = 0, count = 0;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        sc.close();

        if(num > 0) {
            if(num > 1) {
            char[] bin = toBinary(num);
            char[] other = new char[1 + bin.length];

            for(char c: bin) {
                if(c != '\0')
                    count += 1;
            }

            for(i = 0; i < count - 1; i++)
                other[i] = '1';
            other[i] = '0';
            other[i + 1] = '\0';

            ans_one = toDecimal(other);
            if (ans_one < num)
                System.out.println(ans_one);

            other[i] = '1';
            other[0] = '0';

            ans_two = toDecimal(other);
            if (ans_two < num && ans_two != ans_one)
                System.out.println(ans_two);
            }
        } else {
            System.out.println("0");
        }

    }

    public static char[] toBinary(int num) {
        // Converts a number to binary

        char[] ans = new char[1024], ret = new char[1024];
        char digit;
        int i = 0, j = 0, count = 0;
        while(num > 0) {
            digit = (char)((num % 2) + '0');
            ans[i] = digit;
            i++;
            count++;
            num /= 2;
        }
        ans[i] = '\0';

//        String ans_str = new String(ans);
//        System.out.println(ans_str);

//        for(char c: ans) {
//            if(c == '0' || c == '1')
//                System.out.print(c);
//        }

        for(i = count - 1; i >= 0; i--) {
            if(ans[i] == '1' || ans[i] == '0') {
                ret[j] = ans[i];
                j++;
            }
        }
        ret[j] = '\0';

//        System.out.println("");
//        for(char c: ret) {
//            if(c == '0' || c == '1')
//                System.out.print(c);
//        }

        return ret;
    }

    public static int toDecimal(char[] num) {
        int ans = 0, pos = 0, charNum = 0, power = 0;

//        for(char c: num)
//            System.out.print(c);
//        System.out.println("");

        for(int i = num.length - 1; i >= 0; i--) {
            if(num[i] == '0' || num[i] == '1') {
                charNum = (num[i] - '0');
                power = (int)Math.pow(2, (double) pos);
//                System.out.println(num[i] + " " + charNum + " " + power);
                ans += (charNum * power);
                pos++;
            }
        }

//        throw Exception();
        
        return ans;
    }
}