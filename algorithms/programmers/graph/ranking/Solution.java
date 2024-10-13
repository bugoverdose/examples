package bugoverdose.programmers.graph.ranking;

// https://school.programmers.co.kr/learn/courses/30/lessons/49191?language=java

import java.util.*;

class Solution {
    public int solution(int n, int[][] results) {
        Map<Integer, Set<Integer>> winMap = new HashMap<>();
        Map<Integer, Set<Integer>> loseMap = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            winMap.put(i, new HashSet<>());
            loseMap.put(i, new HashSet<>());
        }
        for (int[] r : results) {
            winMap.get(r[0]).add(r[1]);
            loseMap.get(r[1]).add(r[0]);
        }
        int answer = 0;
        for (int curNode = 1; curNode <= n; curNode++) {
            boolean[] visited = new boolean[n+1];
            List<Integer> nextWinners = new ArrayList<>();
            nextWinners.add(curNode);
            while (!nextWinners.isEmpty()) {
                int cur = nextWinners.remove(nextWinners.size()-1);
                if (visited[cur]) {
                    continue;
                }
                visited[cur] = true;
                for (int next : winMap.get(cur)) {
                    if (visited[next]) {
                        continue;
                    }
                    nextWinners.add(next);
                }
            }
            visited[curNode] = false;
            List<Integer> nextLosers = new ArrayList<>();
            nextLosers.add(curNode);
            while (!nextLosers.isEmpty()) {
                int cur = nextLosers.remove(nextLosers.size()-1);
                if (visited[cur]) {
                    continue;
                }
                visited[cur] = true;
                for (int next : loseMap.get(cur)) {
                    if (visited[next]) {
                        continue;
                    }
                    nextLosers.add(next);
                }
            }
            boolean fixed = true;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    fixed = false;
                    break;
                }
            }
            if (fixed) {
                answer++;
            }
        }
        return answer;
    }
}
