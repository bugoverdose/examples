package bugoverdose.programmers.dfsbfs.network;

// https://school.programmers.co.kr/learn/courses/30/lessons/43162?language=java

import java.util.*;

class Solution {

    int[] parents;

    public int solution(int n, int[][] computers) {
        parents = new int[n];
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computers[i][j] == 1) {
                    union(i, j);
                }
            }
        }

        Set<Integer> answers = new HashSet<>();
        for (int i = 0; i < n; i++) {
            answers.add(find(i));
        }
        return answers.size();
    }

    private int find(int cur) {
        if (this.parents[cur] == cur) {
            return cur;
        }
        this.parents[cur] = find(this.parents[cur]);
        return this.parents[cur];
    }

    private void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa < pb) {
            this.parents[pb] = pa;
        } else {
            this.parents[pa] = pb;
        }
    }
}
