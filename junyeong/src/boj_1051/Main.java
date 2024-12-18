package boj_1051;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] num = br.readLine().split(" ");
        int n = Integer.parseInt(num[0]);
        int m = Integer.parseInt(num[1]);
        char[][] arr = new char[n][m];

        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine().toCharArray();
        }

        int maxSize = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 1; i + k < n && j + k < m; k++) {
                    if (arr[i][j] == arr[i][j + k] &&
                            arr[i][j] == arr[i + k][j] &&
                            arr[i][j] == arr[i + k][j + k]
                    ) {
                        maxSize = Math.max(maxSize, (k + 1) * (k + 1));
                    }
                }
            }
        }
        System.out.println(maxSize);
    }
}
