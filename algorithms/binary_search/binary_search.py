# 이분탐색

# 직접 구현
def binary_search1(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1  # 값을 찾지 못한 경우

# ==============================================

# bisect.bisect_left 함수를 활용한 간단 구현
from bisect import bisect_left

def binary_search2(arr, target):
    # 삽입 가능한 최소 인덱스 = 이미 중복되는 값이 존재하는 경우 해당 index 반환
    idx = bisect_left(arr, target)
    # 리스트 범위를 벗어날 수 있음. 
    # 해당 인덱스의 값이 target과 동일한지 확인
    if idx < len(arr) and arr[idx] == target:
        return idx
    return -1  # 값을 찾지 못한 경우

# ==============================================

lst = [1, 3, 3, 4, 7]

for num in range(1, 10):
    # idx = binary_search1(lst, num)
    idx = binary_search2(lst, num)
    if idx != -1:
        print(f"{num}의 index = {idx}")
    else:
        print(f"{num}는 {lst}에 없음")
