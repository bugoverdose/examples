package bugoverdose.programmers.bruteforce.carpet;

// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=java
class Solution {

    public int[] solution(int brown, int yellow) {
        int area = brown + yellow;
        for (int shorter = 1; ; shorter++) {
            if (area % shorter > 0) {
                continue;
            }
            int longer = area / shorter;
            if ((longer - 2) * (shorter - 2) == yellow) {
                return new int[]{longer, shorter};
            }
        }
    }
}
