package bugoverdose.programmers.binarysearch.airport;

// https://school.programmers.co.kr/learn/courses/30/lessons/43238?language=java

class Solution {

    public long solution(int n, int[] times) {
        // int면 틀림. 무조건 long 타입
        long left = 0L;
        long right = 1L;
        for (int t : times) {
            right = Math.max(right, t);
        }
        right *= n;
        while (left <= right) {
            long mid = (left + right) / 2;
            long total = 0;
            for (int t : times) {
                total += (mid / t);
            }
            if (total < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}
