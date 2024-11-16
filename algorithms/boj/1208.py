# 부분수열의 합2 https://www.acmicpc.net/problem/1208
# Meet in the Middle (not 분할정복)

import sys
from itertools import combinations

input = sys.stdin.readline

N, S = map(int, input().split())
elements = list(map(int, input().split()))

answer = 0

def to_sums(half):
    global answer
    sums = []
    for i in range(1, len(half)+1):
        for comb in combinations(half, i):
            cur_sum = 0
            for num in comb:
                cur_sum += num
            if cur_sum == S:
                answer += 1 # 기본 값 추가
            sums.append(cur_sum)
    return sums

if N == 1:
    print(1 if elements[0] == S else 0)
else:
    half1 = sorted(to_sums(elements[:N//2])) # [-3,-2,-1]
    half2 = sorted(to_sums(elements[N//2:]), reverse=True) # [3,2,1]

    idx1, len1 = 0, len(half1)
    idx2, len2 = 0, len(half2)

    while idx1 < len1 and idx2 < len2:
        small, big = half1[idx1], half2[idx2]
        if small + big < S:
            idx1 += 1 # small 값이 증가해서 S에 근접
        elif small + big > S:
            idx2 += 1 # big 값이 감소해서 S에 근접
        else:
            # small + big == S인 경우
            start_idx1, start_idx2 = idx1, idx2
            # 중복된 값이 있으면 끝까지 이동
            while idx1 + 1 < len1:
                if half1[idx1] != half1[idx1 + 1]: break
                idx1 += 1
            while idx2 + 1 < len2:
                if half2[idx2] != half2[idx2 + 1]: break
                idx2 += 1
            answer += (idx1 - start_idx1 + 1) * (idx2 - start_idx2 + 1)
            idx1 += 1
            idx2 += 1

    print(answer)
