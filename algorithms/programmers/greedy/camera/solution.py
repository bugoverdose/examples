# https://school.programmers.co.kr/learn/courses/30/lessons/42884

def solution(routes):
    cameras = []
    routes.sort(key = lambda x:x[1])
    for r in routes:
        [a, b] = r
        detected = False
        for c in cameras:
            if a <= c:
                detected = True
                break
        if detected: continue
        cameras.append(b)
    return len(cameras)

print(solution([[-20,-15], [-14,-5], [-18,-13], [-5,-3]])) # 2
