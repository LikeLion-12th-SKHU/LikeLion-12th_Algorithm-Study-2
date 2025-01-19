package boj_2167;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] size = br.readLine().split(" ");
        int N = Integer.parseInt(size[0]);
        int M = Integer.parseInt(size[1]);

        int[][] array = new int[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            String[] row = br.readLine().split(" ");
            for (int j = 1; j <= M; j++) {
                array[i][j] = Integer.parseInt(row[j - 1]);
            }
        }

        int[][] sum = new int[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                sum[i][j] = array[i][j]
                        + sum[i - 1][j]
                        + sum[i][j - 1]
                        - sum[i - 1][j - 1];
            }
        }

        int K = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for (int k = 0; k < K; k++) {
            String[] query = br.readLine().split(" ");
            int i = Integer.parseInt(query[0]);
            int j = Integer.parseInt(query[1]);
            int x = Integer.parseInt(query[2]);
            int y = Integer.parseInt(query[3]);

            int realSum = sum[x][y]
                    - sum[i - 1][y]
                    - sum[x][j - 1]
                    + sum[i - 1][j - 1];

            sb.append(realSum).append("\n");
        }

        System.out.print(sb);
    }
}
