package bugoverdose.programmers.stackqueue.feature;

import java.util.*;

import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/42586?language=java
class Solution {

    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        LinkedList<Job> jobQueue = new LinkedList<>(); // 큐 없이 그냥 index 증가시키는 방식도 가능.
        for (int i = 0; i < progresses.length; i++) {
            jobQueue.add(new Job(progresses[i], speeds[i]));
        }
        for (int day = 0; day < 100; day++) {
            if (jobQueue.isEmpty()) {
                break;
            }
            int finishedJobCount = 0;
            while (!jobQueue.isEmpty()) {
                Job curJob = jobQueue.peekFirst();
                if (curJob.progress + curJob.speed * day < 100) {
                    break;
                }
                jobQueue.remove(0);
                finishedJobCount += 1;
            }
            if (finishedJobCount > 0) {
                answer.add(finishedJobCount);
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }

    class Job {
        int progress;
        int speed;

        public Job(int progress, int speed) {
            this.progress = progress;
            this.speed = speed;
        }
    }
}
