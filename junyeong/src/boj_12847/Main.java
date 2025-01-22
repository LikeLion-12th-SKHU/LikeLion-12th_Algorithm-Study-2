package boj_12847;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] pay = new int[n];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            pay[i] = Integer.parseInt(st.nextToken());
        }

        long maxEarnings;
        long currentSum = 0;

        for (int i = 0; i < m; i++) {
            currentSum += pay[i];
        }

        maxEarnings = currentSum;

        for (int i = m; i < n; i++) {
            currentSum = currentSum + pay[i] - pay[i - m];
            maxEarnings = Math.max(maxEarnings, currentSum);
        }

        System.out.println(maxEarnings);
    }
}


