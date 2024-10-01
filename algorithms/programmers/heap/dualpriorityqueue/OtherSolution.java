package bugoverdose.programmers.heap.dualpriorityqueue;

// https://school.programmers.co.kr/learn/courses/30/lessons/42628?language=java

import java.util.*;

// 두 큐 동시에 사용하면서 양쪽 모두 최소값/최대값 함께 제거하는 방식
class OtherSolution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (String operation : operations) {
            String[] op = operation.split(" ");
            String command = op[0];
            int number = Integer.parseInt(op[1]);
            if (command.equals("I")) {
                minHeap.add(number);
                maxHeap.add(number);
                continue;
            }
            if (maxHeap.isEmpty()) {
                continue;
            }
            if (number == 1) {
                minHeap.remove(maxHeap.poll());
            } else {
                maxHeap.remove(minHeap.poll());
            }
        }
        if (maxHeap.isEmpty()) {
            return new int[]{0, 0};
        }
        return new int[]{maxHeap.poll(), minHeap.poll()};
    }
}
