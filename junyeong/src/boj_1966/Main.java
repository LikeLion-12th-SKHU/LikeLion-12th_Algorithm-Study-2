package boj_1966;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            String[] dataInfo = br.readLine().split(" ");
            int n = Integer.parseInt(dataInfo[0]);
            int m = Integer.parseInt(dataInfo[1]);

            int[] data = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .toArray();

            Queue<int[]> queue = new LinkedList<>();
            for (int j = 0; j < n; j++) {
                queue.add(new int[]{data[j], j});
            }

            int print = 0;

            while (!queue.isEmpty()) {
                int[] current = queue.poll();
                boolean Priority = queue.stream()
                        .anyMatch(doc -> doc[0] > current[0]);

                if (Priority) {
                    queue.add(current);
                } else {
                    print++;
                    if (current[1] == m) {
                        sb.append(print).append("\n");
                        break;
                    }
                }
            }
        }
        System.out.print(sb);
    }
}
