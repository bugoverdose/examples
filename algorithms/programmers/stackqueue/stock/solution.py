# https://school.programmers.co.kr/learn/courses/30/lessons/42584?language=python3

def solution(prices):
    N = len(prices)
    answer = [0 for _ in range(N)]
    stack = []
    for i in range(N):
        price = prices[i]
        while stack:
            (prev_i, prev) = stack[-1]
            if prev <= price: break
            stack.pop()
            answer[prev_i] = i - prev_i
        stack.append((i, price))
    while stack:
        (prev_i, _) = stack.pop()
        answer[prev_i] = N-1 - prev_i
    return answer

print(solution([1, 2, 3, 2, 3])) # [4, 3, 1, 1, 0]
