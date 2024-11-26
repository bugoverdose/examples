# https://school.programmers.co.kr/learn/courses/30/lessons/43105

def solution(triangle):
    prev_sums = [triangle[0][0]]
    for i in range(1, len(triangle)):
        new_sums = [0 for _ in range(len(triangle[i]))]
        row = triangle[i]
        for j in range(len(prev_sums)):
            new_sums[j] = max(new_sums[j], prev_sums[j] + row[j])
            new_sums[j+1] = max(new_sums[j+1], prev_sums[j] + row[j+1])
        prev_sums = new_sums
    return max(prev_sums)

print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]])) # 30
