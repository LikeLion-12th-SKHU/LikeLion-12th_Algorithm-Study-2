package boj_1764;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        HashSet<String> un1 = new HashSet<>();
        for (int i = 0; i < n; i++) {
            un1.add(br.readLine());
        }

        ArrayList<String> un2 = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            String name = br.readLine();
            if (un1.contains(name)) {
                un2.add(name);
            }
        }

        Collections.sort(un2);

        System.out.println(un2.size());
        for (String name : un2) {
            System.out.println(name);
        }
    }
}