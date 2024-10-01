package bugoverdose.programmers.sort.biggestnumber;

// https://school.programmers.co.kr/learn/courses/30/lessons/42746?language=java

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public String solution(int[] numbers) {
        if (numbers.length == 0) {
            return "0";
        }
        List<Number> arr = new ArrayList<>();
        for (int num : numbers) {
            arr.add(new Number(num));
        }
        String joined = arr.stream()
                .sorted()
                .map(n -> n.value)
                .collect(Collectors.joining());

        // 히든 케이스: "00000" => "0" 변환
        if (joined.startsWith("0")) {
            return "0";
        }
        return joined; // 조건: "정답이 너무 클 수 있으니 문자열로 바꾸어 return"
    }

    class Number implements Comparable<Number> {
        String value;
        String compareVal;

        public Number(int value) {
            this.value = String.valueOf(value);
            this.compareVal = this.value.repeat(4).substring(0, 4);
        }

        @Override
        public int compareTo(Number o) {
            // NOTE: 내림차순 정렬이 되도록 this, o 순서 반대로
            return o.compareVal.compareTo(this.compareVal);
        }
    }
}
