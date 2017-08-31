import java.util.Scanner;

public class day3 {

    public static void main(String[] args) {
        int num = 0;

        // Problem 1: Check if a number is even or odd.
//        System.out.println("\nProblem 1.");
//        num = GetInt();
//        if(even_or_odd(num))
//            System.out.println("Even\n");
//        else
//            System.out.println("Odd\n");

        // Problem 2: Print the nth Fibonacci number.
        // In this scenario, num can't be negative.
        System.out.println("\nProblem 2.");

        do {
            num = GetInt();
            if(num < 0)
                System.out.println("Number can't be negative. Reenter. ");
        } while(num < 0);

//         num = GetInt();
         /*
        while(num < 0) {
            System.out.println("Number can't be negative. Reenter. ");
            num = GetInt();
        } */

        int[] fibs = new int[num];

        if(num > 0) {
            fibs[0] = 1;
            fibs[1] = 1;

            System.out.println(nth_fibo(num, fibs));
        }
        else
            System.out.println("Something went wrong. Sorry about that... :(");
    }

    public static boolean even_or_odd(int num) {
	/*
	 * Checks whether a given number is even or odd.
	 * Returns: 1 if even, 0 if odd (since true and false don't exist in C.)
	 */

        return num % 2 == 0;
    }

    public static int nth_fibo(int n, int[] fibs) {
	/*
	 * Recursively computes the nth Fibonacci number.
	 */

        if(n <= 1)
            return 1;

        if(fibs[n-1] == 0)
		fibs[n-1] = nth_fibo(n - 1, fibs) +
                    nth_fibo(n - 2, fibs);

        return fibs[n-1];

//	return nth_fibo(n - 1, fibs) + nth_fibo(n - 2, fibs);
    }

    public static int GetInt() {
        /*
        What's going on in this function?
        When I enter it for the first time, everything works OK. All the validations are done properly, and it keeps
        asking me until I enter a valid int.
        But, if I call this function in a loop, as I do in main(), then it isn't waiting for my input.
        It's just looping infinitely.
        What am I doing wrong?
         */
        Scanner reader = new Scanner(System.in);
//        reader.reset();
        int ans = 0, len = 0;
        String str = "";

        System.out.print("Enter an integer: ");
        while(true) {
//            str = reader.next();
            try {
                str = reader.next();
                ans = Integer.parseInt(str);
//                reader.reset();
                reader.close();
                return ans;
            }
            catch (Exception e) {
                System.out.print("Invalid. Retry: ");
                reader.next();
//                reader.reset();
            }

        }
    }

}
