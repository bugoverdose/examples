# https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=python3

def solution(brown, yellow):
    total = brown + yellow
    row = 2
    while True:
        row += 1
        if total % row > 0: continue
        col = total // row
        if 2 * (row + col) - 4 == brown:
            return [col, row]

print(solution(10, 2)) # [4, 3]
print(solution(8, 1)) # [3, 3]
print(solution(24, 24)) # [8, 6]
	