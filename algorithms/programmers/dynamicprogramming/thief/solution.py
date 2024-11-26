# https://school.programmers.co.kr/learn/courses/30/lessons/42897

def solution(money):
    dp0 = [0 for _ in range(len(money)-1)] # 0번째 선택 + 마지막 선택 불가
    dp0[0] = money[0]
    dp0[1] = money[1]
    dp0[2] = money[0] + money[2]
    dp1 = [0 for _ in range(len(money))] # 0번째 선택 불가 + 마지막 선택 가능
    dp1[1] = money[1]
    dp1[2] = money[2]

    for i in range(3, len(dp0)):
        dp0[i] = money[i] + max(dp0[i-3], dp0[i-2])
    for i in range(3, len(dp1)):
        dp1[i] = money[i] + max(dp1[i-3], dp1[i-2])

    return max(max(dp0), max(dp1))

print(solution([1, 2, 3, 1])) # 4
