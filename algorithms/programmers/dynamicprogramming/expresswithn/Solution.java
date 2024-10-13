package bugoverdose.programmers.dynamicprogramming.expresswithn;

// https://school.programmers.co.kr/learn/courses/30/lessons/42895?language=java

import java.util.*;

class Solution {

    public int solution(int N, int number) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int i = 1; i < 9; i++) {
            Set<Integer> arr = new HashSet<>();
            arr.add(Integer.valueOf(String.valueOf(N).repeat(i)));
            map.put(i, arr);
        }
        for (int i = 1; i < 9; i++) {
            // i = j + k
            Set<Integer> cur = map.get(i);
            for (int j = 1; j <= i; j++) {
                int k = i - j;
                if (k < j) {
                    break;
                }
                for (int a : map.get(j)) {
                    for (int b : map.get(k)) {
                        cur.add(a + b);
                        cur.add(a * b);
                        cur.add(a - b);
                        cur.add(b - a);
                        if (b != 0) {
                            cur.add(a / b);
                        }
                        if (a != 0) {
                            cur.add(b / a);
                        }
                    }
                }
            }
            for (int c : cur) {
                if (c == number) {
                    return i;
                }
            }
        }
        return -1;
    }
}