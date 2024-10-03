package bugoverdose.programmers.bruteforce.electricity;

// https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=java

class Solution {

    public int solution(int n, int[][] wires) {
        int answer = 999999999;
        for (int disconnected = 0; disconnected < wires.length; disconnected++) {
            Parents parents = new Parents(n);
            for (int i = 0; i < wires.length; i++) {
                if (i == disconnected) {
                    continue;
                }
                parents.union(wires[i][0], wires[i][1]);
            }

            int parentMain = -1;
            boolean otherParentExists = false;
            int diff = 0;
            for (int i = 1; i <= n; i++) {
                int parent = parents.findParent(i);
                if (parentMain == -1 || parentMain == parent) {
                    parentMain = parent;
                    diff++;
                } else {
                    otherParentExists = true;
                    diff--;
                }
            }
            if (otherParentExists) {
                answer = Math.min(answer, Math.abs(diff));
            }
        }
        return answer;
    }

    class Parents {

        private int[] parents;

        public Parents(int n) {
            this.parents = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parents[i] = i;
            }
        }

        private int findParent(int cur) {
            if (parents[cur] == cur) {
                return cur;
            }
            parents[cur] = findParent(parents[cur]);
            return parents[cur];
        }

        private void union(int cur1, int cur2) {
            cur1 = findParent(cur1);
            cur2 = findParent(cur2);
            if (cur1 < cur2) {
                parents[cur2] = cur1;
            } else {
                parents[cur1] = cur2;
            }
        }
    }
}
