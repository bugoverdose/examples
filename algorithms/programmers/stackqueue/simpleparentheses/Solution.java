package bugoverdose.programmers.stackqueue.simpleparentheses;

// https://school.programmers.co.kr/learn/courses/30/lessons/12909
class Solution {
    boolean solution(String s) {
        int openCount = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                openCount += 1;
                continue;
            }
            openCount -= 1;
            if (openCount < 0) {
                return false;
            }
        }
        return openCount == 0;
    }
}
