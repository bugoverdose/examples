package bugoverdose.programmers.sort.hindex;

// https://school.programmers.co.kr/learn/courses/30/lessons/42747?language=java

import java.util.Arrays;

class Solution {
    public int solution(int[] citations) {
        int[] arr = Arrays.stream(citations).sorted().toArray();
        int answer = 0;
        for (int i = 0; i < arr.length; i++) {
            if (i+1 > arr[arr.length - 1 - i]) {
                break;
            }
            answer++;
        }
        return answer;
    }
}
