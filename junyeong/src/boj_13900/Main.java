package boj_13900;

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        long[] numbers = new long[n];

        for (int i = 0; i < n; i++) {
            numbers[i] = Long.parseLong(input[i]);
        }

        long totalSum = 0;
        long currentSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += numbers[i] * currentSum;
            currentSum += numbers[i];
        }

        System.out.println(totalSum);
    }
}




