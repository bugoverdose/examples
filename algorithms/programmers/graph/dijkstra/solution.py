# https://school.programmers.co.kr/learn/courses/30/lessons/49189?language=python3

# 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.

from collections import deque

def solution(n, e):
    MAX = 9_999_999
    edges = dict()
    for i in range(1, n+1):
        edges[i] =[]
    for edge in e:
        [a, b] = edge
        edges[a].append(b)
        edges[b].append(a)
    visited = [False for _ in range(n+1)]
    # 1번 노드까지의 거리
    distances = [MAX for _ in range(n+1)]
    distances[1] = 0
    q = deque([1])
    while q:
        cur = q.popleft()
        if visited[cur]: continue
        visited[cur] = True
        d = distances[cur] + 1
        for next_ in edges[cur]:
            if d < distances[next_]:
                distances[next_] = d
                q.append(next_)
    cur_max = 0
    answer = 0
    for d in distances:
        if d == MAX: continue
        if cur_max < d:
            cur_max = d
            answer = 0
        if cur_max == d:
            answer += 1
    return answer

print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]])) # 3
