# https://school.programmers.co.kr/learn/courses/30/lessons/1843

def solution(arr):
    nums = []
    is_add = []
    for i in range(0, len(arr), 2):
        nums.append(int(arr[i]))
    for i in range(1, len(arr), 2):
        if arr[i] == "+":
            is_add.append(True)
        else:
            is_add.append(False)

    N = len(nums)
    maxes = [[-999999999 for _ in range(N)] for _ in range(N)]
    mins = [[999999999 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        maxes[i][i] = nums[i]
        mins[i][i] = nums[i]
    for step in range(1, N):
        for start_idx in range(0, N-step):
            end_idx = start_idx + step
            for mid_idx in range(start_idx, end_idx):
                max_a = maxes[start_idx][mid_idx]
                min_a = mins[start_idx][mid_idx]
                max_b = maxes[mid_idx+1][end_idx]
                min_b = mins[mid_idx+1][end_idx]

                if is_add[mid_idx]:
                    maxes[start_idx][end_idx] = max(max_a+max_b, maxes[start_idx][end_idx])
                    mins[start_idx][end_idx] = min(min_a+min_b, mins[start_idx][end_idx])
                    continue
                maxes[start_idx][end_idx] = max(max_a-min_b, maxes[start_idx][end_idx])
                mins[start_idx][end_idx] = min(min_a-max_b, mins[start_idx][end_idx])
    return maxes[0][N-1]

print(solution(["1", "-", "3", "+", "5", "-", "8"]))
print(solution(["5", "-", "3", "+", "1", "+", "2", "-", "4"]))
