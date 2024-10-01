package bugoverdose.programmers.sort.kthnumber;

// https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=java

import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();
        for (int[] c : commands) {
            List<Integer> arr = new ArrayList<>();
            for (int i = c[0] - 1; i < c[1]; i++) {
                arr.add(array[i]);
            }
            // NOTE: 전체 정렬 없이 PriorityQueue에 넣고 빼는 등 방법은 다양할 듯
            answer.add(arr.stream()
                    .sorted()
                    .collect(Collectors.toList())
                    .get(c[2] - 1));
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
