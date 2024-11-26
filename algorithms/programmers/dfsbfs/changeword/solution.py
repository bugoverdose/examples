# https://school.programmers.co.kr/learn/courses/30/lessons/43163

def solution(begin, target, words):
    words.append(begin)
    word_change = {}
    for word in words:
        word_change[word] = set()

    for i in range(len(words)):
        a = words[i]
        for j in range(i+1, len(words)):
            b = words[j]
            diff_cnt = 0
            for k in range(len(a)):
                if a[k] == b[k]: continue
                diff_cnt += 1
            if diff_cnt != 1: continue
            word_change[a].add(b)
            word_change[b].add(a)

    cur_words = set([begin])
    for count in range(len(words)):
        if len(cur_words) == 0: break
        next_words = set()
        for cur_word in cur_words:
            for next_word in word_change[cur_word]:
                if next_word == target:
                    return count + 1
                next_words.add(next_word)
        cur_words = next_words
    return 0
