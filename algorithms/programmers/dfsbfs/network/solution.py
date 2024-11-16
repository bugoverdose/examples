# https://school.programmers.co.kr/learn/courses/30/lessons/43162?language=python3

def find(a):
    global parents
    if parents[a] == a:
        return a
    parents[a] = find(parents[a]) # 갱신
    return parents[a]

def union(a, b):
    global parents
    pa = find(a)
    pb = find(b)
    if pa > pb:
        pa, pb = pb, pa
    parents[pb] = pa # 부모를 갱신
    # 주의: 자녀 갱신 필요

def solution(n, computers):
    global parents
    parents = [i for i in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            if computers[i][j] == 1:
                union(i, j)
    for i in range(n):
        find(i) # 자녀들의 부모 일괄 갱신
    return len(set(parents))
