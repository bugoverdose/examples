package bugoverdose.programmers.hash.clothes;

import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/42578?language=java
class Solution {
    public int solution(String[][] clothes) {
        // `같은 이름을 가진 의상은 존재하지 않습니다.` 조건 => 의상 종류별 개수만 센다
        Map<String, Integer> map = new HashMap<>();
        for (String[] cloth : clothes) {
            String clothType = cloth[1];
            int clothCount = 1;
            if (map.containsKey(clothType)) {
                clothCount += map.get(clothType);
            }
            map.put(clothType, clothCount);
        }
        int answer = 1;
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            answer *= (e.getValue() + 1); // 입지 않은 경우까지 고려
        }
        return answer - 1; // 아무것도 입지 않은 경우는 제외
    }
}
