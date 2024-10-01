package bugoverdose.programmers.stackqueue.truck;

import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/42583?language=java
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        LinkedList<Integer> bridgeQueue = new LinkedList<>();
        for (int i = 0; i < bridge_length; i++) {
            bridgeQueue.addLast(0);
        }
        LinkedList<Integer> truckQueue = new LinkedList<>();
        for (int w : truck_weights) {
            truckQueue.addLast(w);
        }
        int answer = 0;
        int bridgeWeight = 0;
        while (bridgeWeight > 0 || !truckQueue.isEmpty()) {
            answer++;
            int removedWeight = bridgeQueue.removeFirst();
            bridgeWeight -= removedWeight;

            if (!truckQueue.isEmpty()) {
                int curTruckWeight = truckQueue.getFirst();
                if (bridgeWeight + curTruckWeight <= weight) {
                    bridgeQueue.addLast(truckQueue.removeFirst());
                    bridgeWeight += curTruckWeight;
                    continue;
                }
            }
            bridgeQueue.addLast(0);
        }
        return answer;
    }
}
