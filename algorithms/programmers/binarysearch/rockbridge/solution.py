# https://school.programmers.co.kr/learn/courses/30/lessons/43236

# 도착지점까지의 거리 distance는 1 이상 1,000,000,000 이하입니다.
# 바위는 1개 이상 50,000개 이하가 있습니다.
# n 은 1 이상 바위의 개수 이하입니다.

# 어떤 바위를 파괴했는지에 대한 정보는 저장할 필요 없음. 개수만 필요.

def solution(distance, rocks, n):
    rocks = list(sorted(rocks + [distance]))
    left, right = 0, 1_000_000_000
    while left <= right:
        mid = (left + right) // 2 # 최소 거리 목표. mid 미만이면 바위 제거
        removed_rock_count = 0

        prev_pos = 0
        for rock in rocks:
            # 최소 거리 이상이면 바위 유지
            if rock - prev_pos >= mid:
                prev_pos = rock
                continue
            # 바위 파괴
            removed_rock_count += 1

        if removed_rock_count > n:
            right = mid - 1
        else:
            left = mid + 1
    return right

print(solution(25, [2, 14, 11, 21, 17], 2)) # 4
print(solution(16, [4, 8, 11], 2)) # 8
