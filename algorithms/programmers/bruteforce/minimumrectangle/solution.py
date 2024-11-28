# https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=python3

def solution(sizes):
    max_num, min_num = 0, 0
    for size in sizes:
        [a, b] = size
        if a < b:
            a, b = b, a
        max_num = max(a, max_num)
        min_num = max(b, min_num)
    return max_num * min_num

print(solution([[60, 50], [30, 70], [60, 30], [80, 40]])) # 4000
print(solution([[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]])) # 120
