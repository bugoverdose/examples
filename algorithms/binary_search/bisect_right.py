from bisect import bisect_right, insort_right

lst = [1, 3, 3, 4, 7]

# bisect_right
# 정렬을 유지하기 위해 삽입할 위치 찾기. 
# 이미 같은 값이 있으면 그 오른쪽 위치 반환.
print(bisect_right(lst, 1))  # 결과: 1
print(bisect_right(lst, 2))  # 결과: 1
print(bisect_right(lst, 3))  # 결과: 3
print(bisect_right(lst, 4))  # 결과: 4
print(bisect_right(lst, 5))  # 결과: 4
print(bisect_right(lst, 6))  # 결과: 4
print(bisect_right(lst, 7))  # 결과: 5
print(bisect_right(lst, 8))  # 결과: 5

# insort_right
# 실제로 원소 삽입
insort_right(lst, 5)
print(lst)  # 결과: [1, 3, 3, 4, 5, 7]

insort_right(lst, 8)
print(lst)  # 결과: [1, 3, 3, 4, 5, 7, 8]
