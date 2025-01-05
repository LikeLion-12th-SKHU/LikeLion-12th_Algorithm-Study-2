package boj_2776;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        int T = Integer.parseInt(reader.readLine());

        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(reader.readLine());
            HashSet<Integer> notebook1 = new HashSet<>();
            StringTokenizer st = new StringTokenizer(reader.readLine());
            for (int i = 0; i < N; i++) {
                notebook1.add(Integer.parseInt(st.nextToken()));
            }

            int M = Integer.parseInt(reader.readLine());
            st = new StringTokenizer(reader.readLine());
            for (int i = 0; i < M; i++) {
                int query = Integer.parseInt(st.nextToken());
                if (notebook1.contains(query)) {
                    result.append("1\n");
                } else {
                    result.append("0\n");
                }
            }
        }

        System.out.print(result);
    }
}
