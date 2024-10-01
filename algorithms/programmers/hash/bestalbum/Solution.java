package bugoverdose.programmers.hash.bestalbum;

import java.util.*;
import java.util.stream.Collectors;

// https://school.programmers.co.kr/learn/courses/30/lessons/42579?language=java
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        Map<String, List<Music>> genreMap = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            String genre = genres[i];
            if (!genreMap.containsKey(genre)) {
                genreMap.put(genre, new ArrayList<>());
            }
            genreMap.get(genre).add(new Music(i, plays[i]));
        }

        // 1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
        List<Map.Entry<String, List<Music>>> sortedGenreMap = genreMap.entrySet()
                .stream()
                .sorted(Comparator.comparingInt(entry -> entry
                        .getValue()
                        .stream()
                        .mapToInt(v -> v.play).sum() * -1)) // 음수로 reverse 처리. (<= `모든 장르는 재생된 횟수가 다릅니다` 조건)
                .collect(Collectors.toList());


        // 가장 많이 재생된 노래를 두 개씩 + 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.

        List<Integer> answer = new ArrayList<>();
        for (Map.Entry<String, List<Music>> entry : sortedGenreMap) {
            for (Music music : entry.getValue().stream().sorted().limit(2).collect(Collectors.toList())) {
                answer.add(music.i);
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }

    class Music implements Comparable<Music> {
        int i;
        int play;

        public Music(int i, int play) {
            this.i = i;
            this.play = play;

        }

        // NOTE: Comparator.reverseOrder())로 뒤집을 필요 없도록 대->소로 정렬되도록 정의하기
        @Override
        public int compareTo(Music o) {
            // 2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
            if (this.play > o.play) {
                return -1; // NOTE: 비교 대상(o)보다 작다 => 음수(-1)
            }
            // 3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
            if (this.i < o.i) {
                return -1;
            }
            if (this.i == o.i) {
                return 0;
            }
            return 1;
        }
    }
}
