# https://school.programmers.co.kr/learn/courses/30/lessons/1844

from collections import deque

d1 = [-1, 1, 0, 0]
d2 = [0, 0, -1, 1]

def solution(maps):
    N, M = len(maps), len(maps[0])
    # 모든 곳을 최대 한곳만 visit + 벽은 접근 못하도록 처리
    visitable = [[False for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if maps[i][j] == 1:
                visitable[i][j] = True
    
     # 우선순위 큐 불필요. 그냥 선입선출 + BFS
    pos = deque([(0, 0, 1)])
    while pos:
        (r, c, cnt) = pos.popleft()
        cnt += 1
        for i in range(4):
            cur_row = r + d1[i]
            cur_col = c + d2[i]
            if cur_row < 0 or cur_row >= N: continue
            if cur_col < 0 or cur_col >= M: continue
            if not visitable[cur_row][cur_col]: continue
            visitable[cur_row][cur_col] = False
            if cur_row == N-1 and cur_col == M-1: return cnt
            pos.append((cur_row, cur_col, cnt))
    return -1
