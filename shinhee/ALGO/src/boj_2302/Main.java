package ALGO.src.boj_2302;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[] arr = new int[M + 2];

        for (int i = 1; i <= M; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        arr[0] = 0;
        arr[M + 1] = N + 1;

        Arrays.sort(arr);

        int[] dp = new int[N + 1];
        dp[0] = 1;
        dp[1] = 1;
        if (N >= 2) {
            dp[2] = 2;
        }

        for (int i = 3; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        long result = 1;

        for (int i = 1; i <= M + 1; i++) {
            int len = arr[i] - arr[i - 1] - 1;
            result *= dp[len];
        }

        System.out.println(result);
    }
}
