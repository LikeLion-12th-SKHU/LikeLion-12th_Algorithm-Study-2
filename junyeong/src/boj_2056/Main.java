package boj_2056;

import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] time, indegree, result;
    static List<List<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        time = new int[N + 1];
        indegree = new int[N + 1];
        result = new int[N + 1];

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());
            int cnt = Integer.parseInt(st.nextToken());

            for (int j = 0; j < cnt; j++) {
                int pre = Integer.parseInt(st.nextToken());
                graph.get(pre).add(i);
                indegree[i]++;
            }
        }

        System.out.println(sort());
    }

    static int sort() {
        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
                result[i] = time[i];
            }
        }

        while (!q.isEmpty()) {
            int now = q.poll();

            for (int next : graph.get(now)) {
                indegree[next]--;
                result[next] = Math.max(result[next], result[now] + time[next]);

                if (indegree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        int minTime = 0;
        for (int i = 1; i <= N; i++) {
            minTime = Math.max(minTime, result[i]);
        }
        return minTime;
    }
}
