package bugoverdose.programmers.greedy.joystick;

// https://school.programmers.co.kr/learn/courses/30/lessons/42860?language=java

import java.util.*;

class Solution {

    private static char[] ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();

    public int solution(String name) {
        HashMap<Character, Integer> moveMap = new HashMap<>();
        for (int i = 0; i < ALPHABETS.length; i++) {
            if (!moveMap.containsKey(ALPHABETS[i])) {
                moveMap.put(ALPHABETS[i], i);
            }
            int rev = ALPHABETS.length - i;
            if (i >= 1 && !moveMap.containsKey(ALPHABETS[rev])) {
                moveMap.put(ALPHABETS[rev], i);
            }
        }
        // 힙에 영향을 미치지 않도록 별도로 계산한다
        int updateCount = 0;
        for (char c : name.toCharArray()) {
            updateCount += moveMap.get(c);
        }
        int length = name.length();
        PriorityQueue<Word> words = new PriorityQueue<>(Comparator.comparingInt(a -> a.count));
        words.add(new Word("A".repeat(length)));
        while (true) {
            Word word = words.poll();
            assert word != null;
            if (name.equals(word.value)) {
                return word.count + updateCount;
            }
            char targetChar = name.charAt(word.idx);
            if (word.value.charAt(word.idx) != targetChar) {
                char[] chars = word.value.toCharArray();
                chars[word.idx] = targetChar;
                words.add(new Word(String.valueOf(chars), word.count, word.idx));
            } else {
                int curIdx = word.idx;
                words.add(new Word(word.value, word.count + 1, (curIdx + 1) % length));
                words.add(new Word(word.value, word.count + 1, (curIdx - 1 + length) % length));
            }
        }
    }

    class Word {

        private final String value;
        private int count;
        private int idx;

        public Word(String word) {
            this.value = word;
        }

        public Word(String chars, int count, int idx) {
            this.value = chars;
            this.count = count;
            this.idx = idx;
        }
    }
}