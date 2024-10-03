package bugoverdose.programmers.bruteforce.mockexam;

// https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=java

import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] sums = new int[3];
        int[] twoPicks = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] threePicks = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        for (int i = 0; i < answers.length; i++) {
            if ((i % 5) + 1 == answers[i]) {
                sums[0]++;
            }
            if (twoPicks[i % 8] == answers[i]) {
                sums[1]++;
            }
            if (threePicks[i % 10] == answers[i]) {
                sums[2]++;
            }
        }
        int maxVal = Arrays.stream(sums).max().getAsInt();
        List<Integer> corrects = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            if (sums[i] == maxVal) {
                corrects.add(i + 1);
            }
        }
        return corrects.stream().mapToInt(a -> a).toArray();
    }
}
