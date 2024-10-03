package bugoverdose.programmers.bruteforce.carpet;

// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=java
class Solution2 {

    public int[] solution(int brown, int yellow) {
        for (int inner_height = 1; ; inner_height++) {
            if (yellow % inner_height != 0) {
                continue;
            }
            int inner_width = yellow / inner_height;
            if ((inner_width + inner_height) * 2 + 4 == brown) {
                int width = Math.max(inner_width, inner_height) + 2;
                int height = Math.min(inner_width, inner_height) + 2;
                return new int[]{width, height};
            }
        }
    }
}