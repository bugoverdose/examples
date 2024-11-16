from bisect import bisect_left, insort_left

lst = [1, 3, 3, 4, 7]

# bisect_left 
# 정렬을 유지하기 위해 삽입할 위치 찾기.
# 이미 같은 값이 있으면 해당 위치를 그대로 반환! => 이진탐색에 활용 가능한 성질
print(bisect_left(lst, 1))  # 결과: 0
print(bisect_left(lst, 2))  # 결과: 1
print(bisect_left(lst, 3))  # 결과: 1
print(bisect_left(lst, 4))  # 결과: 3
print(bisect_left(lst, 5))  # 결과: 4
print(bisect_left(lst, 6))  # 결과: 4
print(bisect_left(lst, 7))  # 결과: 4
# 주의: 리스트 길이를 넘어갈 수도 있음.
print(bisect_left(lst, 8))  # 결과: 5

# insort_left
# 실제로 원소 삽입
insort_left(lst, 5)
print(lst)  # 결과: [1, 3, 3, 4, 5, 7]

insort_left(lst, 8)
print(lst)  # 결과: [1, 3, 3, 4, 5, 7, 8]
