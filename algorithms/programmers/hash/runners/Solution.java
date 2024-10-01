package bugoverdose.programmers.hash.runners;

import java.util.*;
import java.util.Map.Entry;

// https://school.programmers.co.kr/learn/courses/30/lessons/42576?language=java
class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> runners = new HashMap<>();
        for (String p : participant) {
            int runnerCount = 1;
            if (runners.containsKey(p)) {
                runnerCount += runners.get(p);
            }
            runners.put(p, runnerCount);
        }
        for (String c : completion) {
            runners.put(c,  runners.get(c) - 1);
        }
        for (Entry<String, Integer> e : runners.entrySet()) {
            if (e.getValue() > 0) {
                return e.getKey();
            }
        }
        return null;
    }
}
