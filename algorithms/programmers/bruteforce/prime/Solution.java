package bugoverdose.programmers.bruteforce.prime;

// https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=java

import java.util.*;

class Solution {

    Set<Integer> allNumbers = new HashSet<>();

    public int solution(String numbers) {
        char[] chars = numbers.toCharArray();
        boolean[] visited = new boolean[chars.length];
        dfs(chars, "", visited);

        int maxNum = allNumbers.stream()
                .mapToInt(i -> i)
                .max()
                .getAsInt();

        boolean[] notPrimes = createNotPrimes(maxNum);

        int answer = 0;
        for (int num : allNumbers) {
            if (!notPrimes[num]) {
                answer += 1;
            }
        }
        return answer;
    }

    private static boolean[] createNotPrimes(int maxNum) {
        boolean[] notPrimes = new boolean[maxNum + 1]; // 전부 소수로 간주
        notPrimes[0] = true;
        notPrimes[1] = true;
        for (int i = 2; i < Math.sqrt(notPrimes.length) + 1; i++) {
            // 소수인 경우
            if (!notPrimes[i]) {
                for (int j = i * 2; j < notPrimes.length; j += i) {
                    notPrimes[j] = true; // 소수 제거
                }
            }
        }
        return notPrimes;
    }

    private void dfs(char[] chars, String curString, boolean[] visited) {
        if (curString.length() == visited.length) {
            return;
        }
        for (int i = 0; i < visited.length; i++) {
            if (visited[i]) {
                continue;
            }
            String newString = curString + chars[i];
            allNumbers.add(Integer.valueOf(newString));
            visited[i] = true;
            dfs(chars, newString, visited);
            visited[i] = false;
        }
    }
}
