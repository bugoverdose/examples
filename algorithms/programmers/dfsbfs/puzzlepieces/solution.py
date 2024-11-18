# https://school.programmers.co.kr/learn/courses/30/lessons/84021
# 좌표평면 내 조작
# BFS + 좌표평면 rotate

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

def create_squares(table, check_filled):
    N = len(table)
    M = len(table[0])
    pieces = []
    visited = [[False for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if visited[i][j]: continue
            visited[i][j] = True
            if check_filled ^ table[i][j]: continue
            base_pieces = [] # ex. 5번 조각 = [(0,0), (1,0)]
            stack = [(i, j)]
            while stack:
                cur_i, cur_j = stack.pop()
                base_pieces.append((cur_i - i, cur_j - j))
                for d in range(4):
                    next_i = cur_i + dy[d]
                    next_j = cur_j + dx[d]
                    if next_i < 0 or next_i >= N: continue
                    if next_j < 0 or next_j >= M: continue
                    if visited[next_i][next_j]: continue
                    visited[next_i][next_j] = True
                    if check_filled ^ table[next_i][next_j]: continue
                    stack.append((next_i, next_j))
            pieces.append(base_pieces)
    piece_squares = []
    for p in pieces:
        piece_squares.append((len(p), to_squares(p)))
    return piece_squares

# 좌표평면 값으로 변환
# [(0,0), (0,1)] => [[0, 1]]
def to_squares(pieces):
    min_y, max_y = 99, 0
    min_x, max_x = 99, 0
    for p in pieces:
        min_y = min(min_y, p[0])
        max_y = max(max_y, p[0])
        min_x = min(min_x, p[1])
        max_x = max(max_x, p[1])
    max_y -= min_y
    max_x -= min_x
    square = [[0 for _ in range(max_x+1)] for _ in range(max_y+1)]
    for p in pieces:
        square[p[0] - min_y][p[1] - min_x] = 1
    return square

def is_fit(piece_square, space_square):
    if piece_square[0] != space_square[0]:
        return False
    pieces = piece_square[1]
    target = space_square[1]
    N = len(pieces)
    M = len(pieces[0])
    for i in range(4):
        if i > 0:
            target = rotate(target)
        if N != len(target): continue
        if M != len(target[0]): continue
        all_same = True
        for y in range(N):
            for x in range(M):
                if pieces[y][x] != target[y][x]:
                    all_same = False
                    break
            if not all_same: break
        if all_same: return True
    return False

# 핵심
def rotate(square):
    N = len(square)
    M = len(square[0])
    rotated = [[0 for _ in range(N)] for _ in range(M)] # M * N
    for y in range(N):
        for x in range(M):
            rotated[x][N-y-1] = square[y][x]
            # (4,2) => (2, N-4 -1) 
    return rotated

def solution(board, table):
    answer = 0
    pieces = create_squares(table, True)
    targets = create_squares(board, False)
    for p in pieces:
        for idx in range(len(targets)):
            e = targets[idx]
            if is_fit(p, e):
                answer += e[0] # 공간 크기만큼 가산
                # 채줘졌으니 목록에서 제거
                if idx+1 >= len(targets):
                    targets = targets[:idx]
                else:
                    targets = targets[:idx] + targets[idx+1:]
                break
    return answer
