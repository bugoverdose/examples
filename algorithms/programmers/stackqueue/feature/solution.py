# https://school.programmers.co.kr/learn/courses/30/lessons/42586?language=python3

def solution(progresses, speeds):
    answer = [] # progresses는 전부 100 미만
    time = 0
    for i in range(len(progresses)):
        progress, speed = progresses[i], speeds[i]
        # 종료될 때까지 시간 이동
        if progress + speed * time < 100:
            time += (100 - (progress + speed * time)) // speed
            if (100 - (progress + speed * time)) % speed > 0:
                time += 1
            answer.append(0)
        # 종료 처리
        answer[-1] += 1
    return answer

print(solution([93, 30, 55], [1, 30, 5])) # [2, 1]
print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1])) # [1, 3, 2]
