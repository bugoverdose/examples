package bugoverdose.programmers.heap.dualpriorityqueue;

// https://school.programmers.co.kr/learn/courses/30/lessons/42628?language=java

import java.util.*;

// 두 큐 중 하나만 사용하는 방식. 최대힙 <=> 최소힙으로 전환할 때 비용 발생
class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> minQueue = new PriorityQueue<>();
        PriorityQueue<Integer> maxQueue = new PriorityQueue<>(Comparator.reverseOrder());
        for (String opertator : operations) {
            var num = opertator.split(" ")[1];
            if (opertator.startsWith("I")) {
                int newInt = Integer.valueOf(num);
                if (!maxQueue.isEmpty()) {
                    maxQueue.add(newInt);
                } else {
                    minQueue.add(newInt);
                }
                continue;
            }
            if (num.endsWith("-1")) {
                while (!maxQueue.isEmpty()) {
                    minQueue.add(maxQueue.poll());
                }
                minQueue.poll();
            } else {
                while (!minQueue.isEmpty()) {
                    maxQueue.add(minQueue.poll());
                }
                maxQueue.poll();
            }
        }
        if (minQueue.isEmpty() && maxQueue.isEmpty()) {
            return new int[]{0, 0};
        }
        if (maxQueue.isEmpty()) {
            int minVal = minQueue.poll();
            int maxVal = minVal;
            while (!minQueue.isEmpty()) {
                maxVal = minQueue.poll();
            }
            return new int[]{maxVal, minVal};
        }
        int maxVal = maxQueue.poll();
        int minVal = maxVal;
        while (!maxQueue.isEmpty()) {
            minVal = maxQueue.poll();
        }
        return new int[]{maxVal, minVal};
    }
}
