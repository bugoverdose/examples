package bugoverdose.programmers.graph.dijkstra;

// https://school.programmers.co.kr/learn/courses/30/lessons/49189?language=java

import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        Map<Integer, List<Integer>> edgeMap = createEdgeMap(edge);
        int[] distance = new int[n+1];
        boolean[] visited = new boolean[n+1];
        for (int i = 1; i <= n; i++) {
            distance[i] = 99_999;
        }
        PriorityQueue<NextNode> nextNodes = new PriorityQueue<>();
        nextNodes.add(new NextNode(1, 0));
        distance[1] = 0;
        while (!nextNodes.isEmpty()) {
            int cur = nextNodes.poll().nodeNumber;
            if (visited[cur]) {
                continue;
            }
            visited[cur] = true;
            for (int next : edgeMap.get(cur)) {
                if (!visited[next]) {
                    distance[next] = Math.min(distance[next], distance[cur] + 1);
                    nextNodes.add(new NextNode(next, distance[next]));
                }
            }
        }
        int answer = 0;
        int curMaxDistance = 0;
        for (int i = 2; i <= n; i++) {
            if (distance[i] == 99_999) continue;
            if (curMaxDistance < distance[i]) {
                curMaxDistance = distance[i];
                answer = 1;
            } else if (curMaxDistance == distance[i]) {
                answer += 1;
            }
        }
        return answer;
    }

    class NextNode implements Comparable<NextNode> {
        int nodeNumber;
        int curDistance;

        public NextNode(int nodeNumber, int curDistance) {
            this.nodeNumber = nodeNumber;
            this.curDistance = curDistance;
        }

        @Override
        public int compareTo(NextNode o) {
            return this.curDistance - o.curDistance; // 음수면 상대방보다 작은 것으로 처리
        }
    }

    private Map<Integer, List<Integer>> createEdgeMap(int[][] edge) {
        Map<Integer, List<Integer>> edgeMap = new HashMap<>();
        for (int[] e : edge) {
            List<Integer> a;
            if (!edgeMap.containsKey(e[0])) {
                a = new ArrayList<>();
            } else {
                a = edgeMap.get(e[0]);
            }
            a.add(e[1]);
            edgeMap.put(e[0], a);

            List<Integer> b;
            if (!edgeMap.containsKey(e[1])) {
                b = new ArrayList<>();
            } else {
                b = edgeMap.get(e[1]);
            }
            b.add(e[0]);
            edgeMap.put(e[1], b);
        }
        return edgeMap;
    }
}