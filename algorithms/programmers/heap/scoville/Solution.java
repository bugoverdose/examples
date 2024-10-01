package bugoverdose.programmers.heap.scoville;

import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/42626?language=java
class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int s : scoville) {
            heap.add(s);
        }
        int answer = 0;
        while (heap.size() >= 2) {
            if (heap.peek() >= K) {
                break;
            }
            int a = heap.remove();
            int b = heap.remove();
            heap.add(a + (b * 2));
            answer++;
        }
        if (heap.peek() < K) {
            return -1;
        }
        return answer;
    }
}