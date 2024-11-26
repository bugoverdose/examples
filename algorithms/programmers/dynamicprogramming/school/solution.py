# https://school.programmers.co.kr/learn/courses/30/lessons/42898

def solution(m, n, puddles):
    is_puddle = set()
    for p in puddles:
        is_puddle.add((p[0]-1, p[1]-1))
    counts = [[0 for _ in range(n)] for _ in range(m)]
    counts[0][0] = 1
    for i in range(m):
        for j in range(n):
            if (i, j) in is_puddle: continue
            if i >= 1:
                counts[i][j] += counts[i-1][j]
            if j >= 1:
                counts[i][j] += counts[i][j-1]
    return counts[m-1][n-1] % 1_000_000_007

print(solution(4, 3, [[2,2]]))
