package boj_1590;

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder input = new StringBuilder(br.readLine());
        String[] firstLine = input.toString().split(" ");

        int N = Integer.parseInt(firstLine[0]);
        int T = Integer.parseInt(firstLine[1]);

        int minWaitTime = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            input.setLength(0);
            input.append(br.readLine());
            String[] busInfo = input.toString().split(" ");

            int Si = Integer.parseInt(busInfo[0]);
            int Ii = Integer.parseInt(busInfo[1]);
            int Ci = Integer.parseInt(busInfo[2]);

            for (int j = 0; j < Ci; j++) {
                int busTime = Si + j * Ii;
                if (busTime >= T) {
                    minWaitTime = Math.min(minWaitTime, busTime - T);
                    break;
                }
            }
        }

        System.out.println(minWaitTime == Integer.MAX_VALUE ? -1 : minWaitTime);
    }
}

