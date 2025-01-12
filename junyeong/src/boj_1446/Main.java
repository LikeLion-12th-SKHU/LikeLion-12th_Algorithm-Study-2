package boj_1446;

import java.io.*;
import java.util.*;



public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        List<Shortcut> shortcuts = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int length = Integer.parseInt(st.nextToken());

            if (end <= D && end > start && length < end - start) {
                shortcuts.add(new Shortcut(start, end, length));
            }
        }

        int[] distance = new int[D + 1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[0] = 0;

        for (int i = 0; i <= D; i++) {
            if (i > 0) {
                distance[i] = Math.min(distance[i], distance[i - 1] + 1);
            }

            for (Shortcut shortcut : shortcuts) {
                if (shortcut.start == i && distance[i] + shortcut.length < distance[shortcut.end]) {
                    distance[shortcut.end] = distance[i] + shortcut.length;
                }
            }
        }

        System.out.println(distance[D]);
    }
}
class Shortcut {
    int start, end, length;

    public Shortcut(int start, int end, int length) {
        this.start = start;
        this.end = end;
        this.length = length;
    }
}
