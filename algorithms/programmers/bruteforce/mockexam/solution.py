# https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=python3

def solution(answers):
    A = [1, 2, 3, 4, 5]
    B = [2, 1, 2, 3, 2, 4, 2, 5]
    C = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    scores = [0, 0, 0]
    for i in range(len(answers)):
        answer = answers[i]
        scores[0] += A[i % len(A)] == answer
        scores[1] += B[i % len(B)] == answer
        scores[2] += C[i % len(C)] == answer
    
    max_score = max(scores)
    answer = []
    for i in range(3):
        if scores[i] == max_score:
            answer.append(i+1)
    return answer

print(solution([1,2,3,4,5])) # [1]
print(solution([1,3,2,4,2])) # [1,2,3]
