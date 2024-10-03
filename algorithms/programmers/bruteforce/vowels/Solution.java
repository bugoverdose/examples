package bugoverdose.programmers.bruteforce.vowels;

// https://school.programmers.co.kr/learn/courses/30/lessons/84512?language=java

class Solution {

    private int answer = 0;
    private boolean found = false;
    private char[] vowels = new char[]{'A', 'E', 'I', 'O', 'U'};

    public int solution(String word) {
        dfs("", word);
        return answer;
    }

    private void dfs(String cur, String word) {
        if (found || cur.length() == 5) return;
        for (int i = 0; i < 6; i++) {
            if (found) return;
            if (i == 0) {
                continue;
            }
            answer++;
            String next = cur + vowels[i - 1];
            if (next.equals(word)) {
                found = true;
                return;
            }
            dfs(next, word);
        }
    }
}
