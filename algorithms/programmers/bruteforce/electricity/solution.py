# https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=python3

def find(parents, a):
    if parents[a] == a:
        return a
    parents[a] = find(parents, parents[a])
    return parents[a]

def union(parents, a, b):
    pa = find(parents, a)
    pb = find(parents, b)
    if pa > pb:
        pa, pb = pb, pa
    parents[pb] = pa

def solution(n, wires):
    answer = 999
    for disconnected in range(len(wires)):
        parents = [i for i in range(n+1)]
        for i in range(len(wires)):
            if i == disconnected: continue
            [a, b] = wires[i]
            union(parents, a, b)
        for i in range(1, n+1):
            find(parents, i)
        diff = 0
        a = parents[1]
        for i in parents[1:]:
            if i == a:
                diff += 1
            else:
                diff -= 1
        answer = min(answer, abs(diff))
    return answer

print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]])) # 3
print(solution(4, [[1,2],[2,3],[3,4]])) # 0
