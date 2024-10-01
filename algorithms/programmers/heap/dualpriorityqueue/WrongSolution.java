package bugoverdose.programmers.heap.dualpriorityqueue;

// https://school.programmers.co.kr/learn/courses/30/lessons/42628

import java.util.Comparator;
import java.util.PriorityQueue;

// 한쪽만 제가하는 접근방법

// 해결못한 반례
// ["I 10", "I 20", "D 1", "I 30", "I 40", "D -1", "D -1"]
// answer: [40, 40]
// but returns [40, 30]
class WrongSolution {

    int totalLength;
    PriorityQueue<Integer> minQueue;
    PriorityQueue<Integer> maxQueue;

    private void init() {
        totalLength = 0;
        minQueue = new PriorityQueue<>();
        maxQueue = new PriorityQueue<>(Comparator.reverseOrder());
    }

    public int[] solution(String[] operations) {
        init();
        for (String op : operations) {
            var num = op.split(" ")[1];
            if (op.startsWith("I")) {
                int newInt = Integer.valueOf(num);
                totalLength++;
                maxQueue.add(newInt);
                minQueue.add(newInt);
                continue;
            }
            // 제거 후 좌우 조정 작업
            if (totalLength <= 0) {
                continue;
            }
            totalLength--;
            if (num.endsWith("-1")) {
                minQueue.poll();
            } else {
                maxQueue.poll();
            }
            // 이슈: [5,5,5]에서 좌측 2개, 우측 2개를 제거하면 최대힙과 최소힙 모두 [5]가 남게 되므로 전체 길이는 별도로 관리 필요.
            if (totalLength <= 0) {
                this.init();
                continue;
            }
            int minVal = minQueue.peek();
            int maxVal = maxQueue.peek();
            if (minVal > maxVal) {
                this.init();
            }
        }
        if (totalLength <= 0) {
            return new int[]{0, 0};
        }
        return new int[]{maxQueue.peek(), minQueue.peek()};
    }
}
