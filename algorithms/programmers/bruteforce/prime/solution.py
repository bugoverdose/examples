# https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=python3

from itertools import permutations

def is_prime(num):
    if num == 0: return False
    if num == 1: return False
    for i in range(2, int(num ** (1/2)) + 1):
        if num % i == 0: return False
    return True

def solution(numbers):
    nums = []
    for num in numbers:
        nums.append(num)
    all_nums = set()
    for i in range(1, len(numbers)+1):
        for perms in permutations(nums, i):
            all_nums.add(int("".join(perms)))
    answer = 0
    for num in all_nums:
        if is_prime(num):
            answer += 1
    return answer

print(solution("17")) # 3
print(solution("011")) # 2