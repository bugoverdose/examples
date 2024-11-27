# https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=python3

def solution(arr):
    answer = []
    for cur in arr:
        if answer and answer[-1] == cur: continue
        answer.append(cur)
    return answer

print(solution([1,1,3,3,0,1,1])) # [1,3,0,1]
print(solution([4,4,4,3,3])) # [4,3]
