package bugoverdose.programmers.hash.phonebook;

import java.util.*;
import java.util.stream.Collectors;

import java.util.Arrays;

// https://school.programmers.co.kr/learn/courses/30/lessons/42577?language=java
class Solution {
    public boolean solution(String[] phone_book) {
        List<String> sortedList = Arrays.stream(phone_book)
                .sorted()
                .collect(Collectors.toList());
        for (int i = 1; i < sortedList.size(); i++) {
            String prev = sortedList.get(i-1);
            String cur = sortedList.get(i);
            if (cur.startsWith(prev)) {
                return false;
            }
        }
        return true;
    }
}
