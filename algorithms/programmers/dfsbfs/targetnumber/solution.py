# https://school.programmers.co.kr/learn/courses/30/lessons/43165?language=python3

def solution(numbers, target):
    sums = [0]
    for num in numbers:
        cur_sums = []
        for cur_sum in sums:
            cur_sums.append(cur_sum + num)
            cur_sums.append(cur_sum - num)
        sums = cur_sums
    answer = 0
    for s in sums:
        if s == target:
            answer += 1 
    return answer

# ==============================================
# dfs solution
def dfs(cur_idx, cur_val):
    global N, nums, target_num, answer
    if cur_idx >= N:
        if cur_val == target_num:
            answer+= 1
        return
    dfs(cur_idx+1, cur_val + nums[cur_idx])
    dfs(cur_idx+1, cur_val - nums[cur_idx])

def solution(numbers, target):
    global N, nums, target_num, answer
    nums = numbers
    N = len(numbers)
    target_num = target
    answer = 0
    dfs(0, 0)
    return answer
