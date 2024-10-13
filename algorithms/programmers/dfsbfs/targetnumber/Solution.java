package bugoverdose.programmers.dfsbfs.targetnumber;

// https://school.programmers.co.kr/learn/courses/30/lessons/43165?language=java

public class Solution {

    private int[] numbers;
    private int target;
    private int answer;

    public int solution(int[] numbers, int target) {
        this.numbers= numbers;
        this.target= target;
        dfs(0, 0);
        return answer;
    }

    private void dfs(int sum, int idx) {
        if (idx >= numbers.length) {
            if (sum == target) {
                answer++;
            }
            return;
        }
        dfs(sum + this.numbers[idx], idx+1);
        dfs(sum - this.numbers[idx], idx+1);
    }
}
