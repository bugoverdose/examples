package bugoverdose.programmers.stackqueue.process;

import java.util.Arrays;
import java.util.*;
import java.util.stream.Collectors;

// https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=java
class Solution {
    public int solution(int[] priorities, int location) {
        List<Integer> sortedAsc = Arrays.stream(priorities)
                .sorted()
                .boxed()
                .collect(Collectors.toList());

        LinkedList<Solution.Job> queue = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
            int priority = priorities[i];
            queue.add(new Solution.Job(priority, i == location));
        }
        int answer = 0;
        while (!queue.isEmpty()) {
            Solution.Job cur = queue.removeFirst();
            if (cur.priority == sortedAsc.get(sortedAsc.size() - 1)) {
                answer += 1;
                sortedAsc.remove(sortedAsc.size() - 1);
                if (cur.isTarget) {
                    return answer;
                }
                continue;
            }
            queue.addLast(cur);
        }
        return 0;
    }

    class Job {
        int priority;
        boolean isTarget;

        public Job(int priority, boolean isTarget) {
            this.priority = priority;
            this.isTarget = isTarget;
        }
    }
}