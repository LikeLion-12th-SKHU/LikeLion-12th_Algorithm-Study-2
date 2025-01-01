package boj_4158;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String[] nm = br.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);

            if (n == 0 && m == 0) {
                break;
            }

            int[] sanggeun = new int[n];
            for (int i = 0; i < n; i++) {
                sanggeun[i] = Integer.parseInt(br.readLine());
            }

            int[] sunyoung = new int[m];
            for (int i = 0; i < m; i++) {
                sunyoung[i] = Integer.parseInt(br.readLine());
            }

            Arrays.sort(sanggeun);

            int commonCount = 0;
            for (int cd : sunyoung) {
                if (binarySearch(sanggeun, cd) == 1) {
                    commonCount++;
                }
            }

            sb.append(commonCount).append("\n");
        }

        System.out.print(sb);
    }

    public static int binarySearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return 0;
    }
}
