package bugoverdose.programmers.stackqueue.samenumber;

import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=java
public class Solution {
    public int[] solution(int[] arr) {
        List<Integer> answer = new ArrayList<>();
        for (int num : arr) {
            while (answer.size() > 0) {
                Integer lastNum = answer.get(answer.size()-1);
                if (num != lastNum) {
                    break;
                }
                answer.remove(answer.size()-1);
            }
            answer.add(num);
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
