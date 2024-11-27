# https://school.programmers.co.kr/learn/courses/30/lessons/42861

# 그래프. 유니온 파인드

def find(parents, cur):
    if parents[cur] == cur:
        return cur
    parents[cur] = find(parents, parents[cur])
    return parents[cur]

def union(parents, a, b):
    pa = find(parents, a)
    pb = find(parents, b)
    if pa > pb:
        pa, pb = pb, pa
    parents[pb] = pa

def solution(n, costs):
    answer = 0
    costs.sort(key = lambda x:x[2])
    parents = [i for i in range(n)]
    for cost in costs:
        [a, b, c] = cost
        pa = find(parents, a)
        pb = find(parents, b)
        if pa == pb: continue
        union(parents, pa, pb)
        answer += c
    return answer

print(solution(4, [[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]])) # 4
