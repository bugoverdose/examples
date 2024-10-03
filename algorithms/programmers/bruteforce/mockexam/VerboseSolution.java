package bugoverdose.programmers.bruteforce.mockexam;

// https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=java

import java.util.*;

class VerboseSolution {
    public int[] solution(int[] answers) {
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        List<Integer> answers2 = List.of(2, 1, 2, 3, 2, 4, 2, 5);
        List<Integer> answers3 = List.of(3, 3, 1, 1, 2, 2, 4, 4, 5, 5);
        for (int i = 0; i < answers.length; i++) {
            if ((i % 5) + 1 == answers[i]) {
                sum1++;
            }
            if (answers2.get(i % 8) == answers[i]) {
                sum2++;
            }
            if (answers3.get(i % 10) == answers[i]) {
                sum3++;
            }
        }
        List<Integer> sums = List.of(sum1, sum2, sum3);
        int maxVal = sums.stream().mapToInt(a -> a).max().getAsInt();
        List<Integer> corrects = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            if (sums.get(i) == maxVal) {
                corrects.add(i+1);
            }
        }
        return corrects.stream().mapToInt(a -> a).toArray();
    }
}
