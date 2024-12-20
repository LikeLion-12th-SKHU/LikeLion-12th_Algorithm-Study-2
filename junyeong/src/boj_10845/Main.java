package boj_10845;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Queue<Integer> queue = new LinkedList<>();

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            String command = input[0];
            if (input.length != 1) {
                int num = Integer.parseInt(input[1]);
                if (command.equals("push")) {
                    queue.add(num);
                }
            } else if (command.equals("pop")) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                } else {
                    System.out.println(queue.remove());
                }
            } else if (command.equals("size")) {
                System.out.println(queue.size());
            } else if (command.equals("empty")) {
                if (queue.isEmpty()) {
                    System.out.println(1);
                } else {
                    System.out.println(0);
                }
            } else if (command.equals("front")) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                } else {
                    System.out.println(queue.peek());
                }
            } else if (command.equals("back")) {
                if (queue.isEmpty()) {
                    System.out.println(-1);
                } else {
                    System.out.println(((LinkedList<Integer>) queue).getLast());
                }
            }
        }
    }
}
