package bugoverdose.programmers.hash.pokemon;

import java.util.Arrays;
import java.util.stream.Collectors;

// https://school.programmers.co.kr/learn/courses/30/lessons/1845
class Solution {
    public int solution(int[] nums) {
        int count = Arrays.stream(nums)
                .boxed()
                .collect(Collectors.toSet())
                .size();
        return Math.min(count, nums.length / 2);
    }
}
