# https://school.programmers.co.kr/learn/courses/30/lessons/42885

from collections import deque

def solution(people, limit):
    answer = 0
    people.sort(reverse = True)
    q = deque(people)
    while q:
        big = q.popleft()
        if len(q) > 0:
            left = q[-1]
            if big + left <= limit:
                q.pop()
        answer += 1
    return answer

print(solution([70, 50, 80, 50], 100)) # 3
print(solution([70, 80, 50], 100)) # 3
