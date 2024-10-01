package bugoverdose.programmers.stackqueue.stock;

import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/42584?language=java
class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        LinkedList<Price> prevPrices = new LinkedList<>();
        for (int i = 0; i < prices.length; i++) {
            int curPrice = prices[i];
            while (!prevPrices.isEmpty()) {
                if (prevPrices.peekLast().price <= curPrice) {
                    break;
                }
                Price prev = prevPrices.removeLast();
                answer[prev.addedTime] = i - prev.addedTime;
            }
            prevPrices.addLast(new Price(curPrice, i));
        }
        while (!prevPrices.isEmpty()) {
            Price prev = prevPrices.removeLast();
            answer[prev.addedTime] = prices.length - 1 - prev.addedTime;
        }
        return answer;
    }

    class Price {
        int price;
        int addedTime;

        public Price(int price, int addedTime) {
            this.price = price;
            this.addedTime = addedTime;
        }
    }
}
