# https://school.programmers.co.kr/learn/courses/30/lessons/42860?language=python3

from string import ascii_uppercase
import heapq

def solution(name):
    N = len(name)
    answer = 0

    change_cnt = {}
    for i in range(0, 14):
        if ascii_uppercase[i] not in change_cnt:
            change_cnt[ascii_uppercase[i]] = i
        if ascii_uppercase[-i] not in change_cnt:
            change_cnt[ascii_uppercase[-i]] = i
    for i in range(N):
        answer += change_cnt[name[i]]

    need_visit = [0 for _ in range(N)]
    for i in range(N):
        if name[i] != "A":
            need_visit[i] = 1
    q = []
    heapq.heappush(q, (0, need_visit, 0))
    while q:
        (move, need_visit, cur_idx) = heapq.heappop(q)
        need_visit = list(need_visit)
        need_visit[cur_idx] = 0
        if max(need_visit) == 0:
            answer += move
            break
        heapq.heappush(q, (move+1, need_visit, (cur_idx+1) % N))
        heapq.heappush(q, (move+1, need_visit, (cur_idx-1 + N) % N))
    return answer

print(solution("JEROEN")) # 56
print(solution("JAN")) # 23
