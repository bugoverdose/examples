# https://school.programmers.co.kr/learn/courses/30/lessons/42626?language=python3

from heapq import heapify, heappush, heappop

def solution(scoville, k):
    answer = 0
    heapify(scoville)
    while True:
        if len(scoville) <= 1: break
        if scoville[0] >= k: break
        a = heappop(scoville)
        b = heappop(scoville)
        heappush(scoville, a + 2*b)
        answer += 1
    if scoville[0] < k:
        return -1
    return answer

print(solution([1, 2, 3, 9, 10, 12], 7)) # 2
