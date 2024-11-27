# https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=python3

from collections import deque

def solution(pri, location):
    answer = 0
    priorities = list(sorted(pri))
    q = deque([])
    for i in range(len(pri)):
        q.append((pri[i], i == location))
    while q:
        (priority, ok) = q.popleft()
        if priorities[-1] == priority:
            priorities.pop()
            answer += 1
            if ok: return answer
        else:
            q.append((priority, ok))

print(solution([2, 1, 3, 2], 2)) # 1
print(solution([1, 1, 9, 1, 1, 1], 0)) # 5
