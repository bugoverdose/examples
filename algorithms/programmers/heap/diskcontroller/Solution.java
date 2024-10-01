package bugoverdose.programmers.heap.diskcontroller;

// https://school.programmers.co.kr/learn/courses/30/lessons/42627?language=java

import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[][] jobs) {
        PriorityQueue<Job> heap = new PriorityQueue<>(Comparator.comparing(job -> job.neededTime));
        List<Job> jobList = Arrays.stream(jobs)
                .map(job -> new Job(job[0], job[1]))
                .sorted(Comparator.comparingInt(job -> -job.inTime)) // 같은 시점에 여러 작업이 들어오더라도 전부 함께 힙에 넣으므로 문제 없음.
                .collect(Collectors.toList());

        int answer = 0;
        int curTime = 0;
        while (!heap.isEmpty() || !jobList.isEmpty()) {
            while (!jobList.isEmpty()) {
                if (jobList.get(jobList.size() - 1).inTime > curTime) {
                    break;
                }
                heap.add(jobList.remove(jobList.size() - 1));
            }
            if (heap.isEmpty()) {
                curTime++;
                continue;
            }
            Job curJob = heap.remove();
            curTime += curJob.neededTime;
            answer += (curTime - curJob.inTime);
        }
        return answer / jobs.length;
    }

    class Job {
        int inTime;
        int neededTime;

        public Job(int inTime, int neededTime) {
            this.inTime = inTime;
            this.neededTime = neededTime;
        }
    }
}