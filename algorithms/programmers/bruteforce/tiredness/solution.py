# https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=python3

from itertools import permutations

def solution(k, dungeons):
    answer = 0
    for perm in permutations(dungeons, len(dungeons)):
        count = 0
        cur = k
        for d in perm:
            [needed, cost] = d
            if needed > cur: continue
            cur -= cost # NOTE: "최소 필요 피로도"는 항상 "소모 피로도"보다 크거나 같습니다.
            count += 1
        answer = max(answer, count)
    return answer

print(solution(80, [[80,20],[50,40],[30,10]])) # 3
