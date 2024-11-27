# https://school.programmers.co.kr/learn/courses/30/lessons/42628?language=python3

# I 숫자 : 큐에 주어진 숫자를 삽입합니다.
# D 1 : 큐에서 최댓값을 삭제합니다.
# D -1 : 큐에서 최솟값을 삭제합니다.

# 이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.

# [1,2,3,4] => 1,2 제거 => [3,4] & [4,3,2,1]
# 9,10 추가 => [3,4,9,10] & [10,9,4,3,2,1]
# 3,4,9,10 제거 => [3,4,9,10] & [2,1] => [] & []로 비우기

from heapq import heappush, heappop, heapify

def pop_max(q):
    if len(q) == 0:
        return [0, []]
    q = sorted(q)
    max_val = q[len(q)-1]
    q.pop()
    heapify(q)
    return [max_val, q]

def solution(operations):
    min_heap = []

    for op in operations:
        o, num = op.split(" ")
        num = int(num)
        if o == "I":
            heappush(min_heap, num)
            continue
        if min_heap:
            if num == 1:
                min_heap = pop_max(min_heap)[1]
            elif num == -1:
                heappop(min_heap)

    if len(min_heap) == 0:
        return [0, 0]
    return [pop_max(min_heap)[0], heappop(min_heap)]

print(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"])) # [0,0]
print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"])) # [333, -45]

# 엣지 케이스 : 우선순위 큐 두 개를 활용하는 경우, 같은 요소가 다른 쪽에서 중복으로 제거되는 이슈
print(solution(["I 10", "I 20", "D 1", "I 30", "I 40", "D -1", "D -1" ])) # [40, 40]
# [10] [10]
# [10, 20] [20, 10]
# D 1 : [10, 20] [10]
# [10, 20, 30] [30, 10]
# [10, 20, 30, 40] [40, 30, 10]
# D -1 : [20, 30, 40] [40, 30, 10] 
# D -1 : [30, 40] [40, 30, 10] => 20 또 제거됨

# ========================================================================================================

# 우선순위 큐 두 개 사용하는 경우 - 일부 테스트 케이스 실패

from heapq import heappush, heappop

def double_queue_solution(operations):
    max_heap, min_heap = [], []
    cnt_map = {}
    for op in operations:
        o, num = op.split(" ")
        num = int(num)
        if o == "I":
            heappush(max_heap, -num)
            heappush(min_heap, num)
            if num not in cnt_map:
                cnt_map[num] = 0
            cnt_map[num] += 1
            continue

        if num == 1:
            while max_heap:
                # 다른 쪽에서 이미 전부 제거된 경우 그대로 제거
                max_num = -heappop(max_heap)
                if cnt_map[max_num] > 0:
                    cnt_map[max_num] -= 1
                    break
            if len(max_heap) == 0: 
                min_heap = []
        elif num == -1:
            while min_heap:
                # 다른 쪽에서 이미 전부 제거된 경우 그대로 제거
                min_num = heappop(min_heap)
                if cnt_map[min_num] > 0:
                    cnt_map[min_num] -= 1
                    break
            if len(min_heap) == 0:
                max_heap = []
        # 각 작업에 대해 진행 필요. 위쪽에서 continue 쓰지 말기
        if max_heap and min_heap and -max_heap[0] < min_heap[0]:
            max_heap, min_heap = [], []

    if len(max_heap) == 0:
        return [0, 0]
    return [-heappop(max_heap), heappop(min_heap)]

# print(double_queue_solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"])) # [0,0]
# print(double_queue_solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"])) # [333, -45]
# print(double_queue_solution(["I 10", "I 20", "D 1", "I 30", "I 40", "D -1", "D -1" ])) # [40, 40]
