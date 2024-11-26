# https://school.programmers.co.kr/learn/courses/30/lessons/43238?language=python3
# 
# bisect.bisect_left로는 풀기 어려움. 직접 이분탐색 구현.

def solution(n, times):
    left, right = 0, 1_000_000_000 * 1_000_000_000 + 1
    while left <= right:
        mid = (left + right) // 2
        people = 0
        for t in times:
            people += mid // t
        if people >= n:
            right = mid - 1
        else:
            left = mid + 1
            # left가 people == n이 되는 최소값에 도달했을 때 left > right되면서 exit => left 그대로 사용
    return left

print(solution(6, [7, 10])) # 28
