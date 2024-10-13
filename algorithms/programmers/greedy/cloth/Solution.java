package bugoverdose.programmers.greedy.cloth;

// https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=java

class Solution {

    public int solution(int n, int[] lost, int[] reserve) {
        int[] clothes = new int[n + 1];
        for (int l : lost) {
            clothes[l] -= 1;
        }
        for (int r : reserve) {
            clothes[r] += 1;
        }
        for (int i = 1; i <= n; i++) {
            if (clothes[i] >= 0) {
                continue;
            }
            if (i - 1 >= 1 && clothes[i - 1] > 0) {
                clothes[i - 1] -= 1;
                clothes[i] += 1;
            } else if (i + 1 <= n && clothes[i + 1] > 0) {
                clothes[i + 1] -= 1;
                clothes[i] += 1;
            }
        }
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            if (clothes[i] >= 0) {
                answer++;
            }
        }
        return answer;
    }
}
