package boj_5576;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        System.out.println(inviteCount(graph, n));
    }

    private static int inviteCount(List<List<Integer>> graph, int n) {
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> queue = new LinkedList<>();

        queue.add(1);
        visited[1] = true;

        int inviteCount = 0;
        int depth = 0;

        while (!queue.isEmpty() && depth < 2) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int current = queue.poll();

                for (int friend : graph.get(current)) {
                    if (!visited[friend]) {
                        visited[friend] = true;
                        queue.add(friend);
                        inviteCount++;
                    }
                }
            }
            depth++;
        }

        return inviteCount;
    }
}
