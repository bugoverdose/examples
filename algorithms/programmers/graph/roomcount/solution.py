# https://school.programmers.co.kr/learn/courses/30/lessons/49191?language=python3

# 해설 (https://yabmoons.tistory.com/606)

# 방 생성의 조건
# 1) 이전에 사용한 적 없는 간선을 활용해서
# 2) 이미 도달했던 정점에 다시 도달한다

# 예외 처리
# - 정점 사이 영역을 교차하는 경우 대응 필요
# - 같은 정점들을 반복적으로 오가는 경우는 무시되도록 처리

dx = [0, 1, 1, 1, 0, -1, -1, -1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

def solution(arrows):
    answer = 0
    visited_nodes = set()
    visited_edges = set()
    cur = (0, 0)
    visited_nodes.add(cur)
    for arr in arrows:
        # 정점들 사이 구간 대응하기 위해 모든 것을 2배수 처리
        for _ in range(2):
            x, y = cur[0] + dx[arr], cur[1] + dy[arr]
            next_ = (x, y)
            if next_ in visited_nodes:
                if (cur, next_) not in visited_edges:
                    answer += 1
            visited_nodes.add(next_)
            visited_edges.add((cur, next_))
            visited_edges.add((next_, cur)) # 같은 정점들을 반복적으로 오가는 경우 필터링되도록 처리 
            cur = next_
    return answer

print(solution([6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0])) # 3
