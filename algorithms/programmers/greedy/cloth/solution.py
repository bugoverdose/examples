# https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=python3

def solution(n, lost, reserve):
    clothes = [0 for _ in range(n+1)]
    for l in lost:
        clothes[l] -= 1
    for r in reserve:
        clothes[r] += 1
    for i in range(1, n+1):
        if clothes[i] == 0: continue
        if clothes[i] < 0 and clothes[i-1] > 0:
            clothes[i-1] -= 1
            clothes[i] += 1
        elif clothes[i-1] < 0 and clothes[i] > 0:
            clothes[i] -= 1
            clothes[i-1] += 1

    answer = 0
    for i in range(1, n+1):
        if clothes[i] >= 0:
            answer += 1
    return answer

print(solution(5, [2, 4], [1, 3, 5])) # 5