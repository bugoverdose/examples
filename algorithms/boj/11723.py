# [비트마스크] 집합 https://www.acmicpc.net/problem/11723

# 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
# add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
# remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
# check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
# toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
# all: S를 {1, 2, ..., 20} 으로 바꾼다.
# empty: S를 공집합으로 바꾼다.

import sys

input = sys.stdin.readline

S = 0

def add(x):
    return (S | (1 << x)) # OR 연산으로 추가

def remove(x):
    return (S & (~(1 << x))) # NOT과 AND 연산으로 제거

def check(x):
    if (S & (1 << x)) > 0:
        print(1)
    else:
        print(0)

def toggle(x):
    return (S ^ (1 << x)) # XOR 연산으로 토글

for _ in range(int(input())):
    command = input()

    if command[:3] == "all":
        S = 0b11111111111111111111
    elif command[:3] == "add":
        S = add(int(command[4:])-1)
    elif command[:5] == "check":
        check(int(command[6:])-1)
    elif command[:5] == "empty":
        S = 0
    elif command[:6] == "toggle":
        S = toggle(int(command[7:])-1)
    elif command[:6] == "remove":
        S = remove(int(command[7:])-1)
