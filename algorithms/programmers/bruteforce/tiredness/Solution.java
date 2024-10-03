package bugoverdose.programmers.bruteforce.tiredness;

// https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=java

class Solution {

    int answer = 0;

    public int solution(int k, int[][] dungeons) {
        dfs(k, new boolean[dungeons.length], dungeons, 0);
        return answer;
    }

    private void dfs(int curTiredness, boolean[] visited, int[][] dungeons, int num) {
        this.answer = Math.max(this.answer, num);
        for (int i = 0; i < dungeons.length; i++) {
            if (visited[i]) {
                continue;
            }
            if (curTiredness >= dungeons[i][0] && curTiredness >= dungeons[i][1]) {
                visited[i] = true;
                curTiredness -= dungeons[i][1];
                dfs(curTiredness, visited, dungeons, num + 1);
                curTiredness += dungeons[i][1];
                visited[i] = false;
            }
        }
    }
}
