# https://school.programmers.co.kr/learn/courses/30/lessons/42883

# 어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
# - NOT 목록 내 가장 작은 숫자들 제거

def solution(number, k):
    N = len(number) - k
    stack = []
    removed_cnt = 0
    for num in number:
        while stack and removed_cnt < k:
            if int(stack[-1]) >= int(num): break
            stack.pop()
            removed_cnt += 1
        stack.append(num)
    return "".join(stack)[:N]

print(solution("1924", 2)) # "94"
print(solution("1231234", 3)) # "3234"
print(solution("4177252841", 4)) # "775841"
