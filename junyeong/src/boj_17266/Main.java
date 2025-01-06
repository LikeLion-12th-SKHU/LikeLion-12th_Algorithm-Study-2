package boj_17266;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[] positions = new int[M];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            positions[i] = Integer.parseInt(st.nextToken());
        }

        int left = 1;
        int right = N;
        int result = N;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (light(positions, N, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        System.out.println(result);
    }

    private static boolean light(int[] positions, int N, int height) {
        int covered = 0;

        for (int position : positions) {
            if (covered < position - height) {
                return false;
            }
            covered = position + height;
        }

        return covered >= N;
    }
}
