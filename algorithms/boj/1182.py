# 부분수열의 합 https://www.acmicpc.net/problem/1182

# N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

import sys
from itertools import combinations

input = sys.stdin.readline

N, S = map(int, input().split())
elements = list(map(int, input().split()))

answer = 0

for length in range(1, N+1):
    for comb in combinations(elements, length):
        cur_sum = 0
        for num in comb:
            cur_sum += num
        if cur_sum == S:
            answer += 1

print(answer)

# =========================================

# 비트마스킹 기반 부분집합 - SLOW!

import sys

input = sys.stdin.readline

N, S = map(int, input().split())
elements = list(map(int, input().split()))

answer = 0

# N = 5
# 00000 = 공집합
# 11111 = (1 << N) - 1
for i in range(1, 1 << N):
    cur_sum = 0
    for j in range(N):
        if i & (1 << j):
            cur_sum += elements[j]
    if cur_sum == S:
        answer += 1

print(answer)
