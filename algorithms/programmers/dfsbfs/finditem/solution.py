# https://school.programmers.co.kr/learn/courses/30/lessons/87694

# 아이템 줍기

# (x1, y1) => (x2, y2)로의 이동 가능 여부 고려
# 이때 x, y가 정수가 아니면서 직사각형 내부인 영역까지 전부 고려 => 2배수하기 등

from collections import deque

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def is_inside(x, y, next_x, next_y, rectangle):
    for rect in rectangle:
        [x1, y1, x2, y2] = rect
        if x1 * 2 < x + next_x and x + next_x < x2 * 2 and y1 * 2 < y + next_y and y + next_y < y2 * 2:
            return True
    return False

def solution(rectangle, characterX, characterY, itemX, itemY):
    possible_paths = set()
    for rect in rectangle:
        [x1, y1, x2, y2] = rect
        for x in range(x1, x2):
            possible_paths.add((x, y1, x+1, y1))
            possible_paths.add((x+1, y1, x, y1))
            possible_paths.add((x, y2, x+1, y2))
            possible_paths.add((x+1, y2, x, y2))
        for y in range(y1, y2):
            possible_paths.add((x1, y, x1, y+1))
            possible_paths.add((x1, y+1, x1, y))
            possible_paths.add((x2, y, x2, y+1))
            possible_paths.add((x2, y+1, x2, y))

    positions = deque([(characterX, characterY, 0)])
    visited = set()
    while positions:
        (x, y, dist) = positions.popleft()
        if x == itemX and y == itemY:
            return dist
        if (x, y) in visited: continue
        visited.add((x, y))
        for i in range(4):
            next_x = x + dx[i]
            next_y = y + dy[i]
            if (next_x, next_y) in visited: continue
            if (x, y, next_x, next_y) not in possible_paths: continue
            if is_inside(x, y, next_x, next_y, rectangle): continue
            positions.append((next_x, next_y, dist+1))


print(solution([[1,1,7,4],[3,2,5,5],[4,3,6,9],[2,6,8,8]], 1, 3, 7, 8)) # 17
print(solution([[1,1,8,4],[2,2,4,9],[3,6,9,8],[6,3,7,7]], 9, 7, 6, 1)) # 11
print(solution([[1,1,5,7]], 1, 1, 4, 7)) # 9
print(solution([[2, 2, 5, 5], [1, 3, 6, 4], [3, 1, 4, 6]], 1, 4, 6, 3)) # 10

# =====================================================================

# slow

from collections import deque

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def inside_rectangle(x, y, next_x, next_y):
    global rectangles, inside
    X = (x + next_x)
    Y = (y + next_y)
    if (X, Y) in inside:
        return inside[(X, Y)]

    for rect in rectangles:
        [x1, y1, x2, y2] = rect
        if x1 * 2 < X < x2 * 2 and y1 * 2 < Y < y2 * 2:
            inside[(X, Y)] = True
            return True

    inside[(X, Y)] = False
    return False

def slow_solution(rectangle, characterX, characterY, itemX, itemY):
    global rectangles, inside
    rectangles = rectangle
    inside = dict()

    # 테두리 이동 가능
    valid_path = set()
    for rect in rectangle:
        [x1, y1, x2, y2] = rect
        for x in range(x1, x2):
            valid_path.add((x, y1, x+1, y1))
            valid_path.add((x, y2, x+1, y2))
            valid_path.add((x+1, y1, x, y1))
            valid_path.add((x+1, y2, x, y2))
        for y in range(y1, y2):
            valid_path.add((x1, y, x1, y+1))
            valid_path.add((x2, y, x2, y+1))
            valid_path.add((x1, y+1, x1, y))
            valid_path.add((x2, y+1, x2, y))

    paths = deque([])
    paths.append([characterX, characterY, 0])
    while True:
        [cur_x, cur_y, d] = paths.popleft()
        for i in range(4):
            x = cur_x + dx[i]
            y = cur_y + dy[i]
            if x == itemX and y == itemY: return d+1
            if x <= 0 or x >= 51: continue
            if y <= 0 or y >= 51: continue
            if not ((cur_x, cur_y, x, y) in valid_path): continue
            if inside_rectangle(cur_x, cur_y, x, y): continue
            paths.append([x, y, d+1])

# =====================================================================

# wrong

from collections import deque

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def wrong_solution(rectangle, characterX, characterY, itemX, itemY):
    global rectangles, inside
    rectangles = rectangle
    inside = dict()

    # 테두리 이동 가능
    path = set()
    for rect in rectangle:
        [x1, y1, x2, y2] = rect
        for x in range(x1, x2):
            path.add((x, y1, x+1, y1))
            path.add((x, y2, x+1, y2))
        for y in range(y1, y2):
            path.add((x1, y, x1, y+1))
            path.add((x2, y, x2, y+1))

    # 가능한 경로들만 최대한 필터링해야 시간 감소
    valid_path = set()
    for p in path:
        (x1, y1, x2, y2) = p
        inside = False
        for rect in rectangles:
            [x, y, X, Y] = rect
            if x * 2 < x1+x2 < X * 2 and y * 2 < y1+y2 < Y * 2:
                inside = True
                break
        if not inside:
            valid_path.add((x1, y1, x2, y2))
            valid_path.add((x2, y2, x1, y1))

    visited = set()
    paths = [(0, characterX, characterY)]
    paths = deque([])
    paths.append([characterX, characterY, 0])
    while paths:
        [cur_x, cur_y, d] = paths.popleft()
        if (cur_x, cur_y) in visited: continue
        visited.add((cur_x, cur_y))
        for i in range(4):
            x = cur_x + dx[i]
            y = cur_y + dy[i]
            if x == itemX and y == itemY: return d+1
            if x <= 0 or x >= 51 or y <= 0 or y >= 51: continue
            if not ((cur_x, cur_y, x, y) in valid_path): continue
            paths.append([x, y, d+1])

# =====================================================================

# wrong : 직사각형 내부의 (x,y)가 정수값들인 경우들만 고려한 경우
# wrong_solution([[2, 2, 5, 5], [1, 3, 6, 4], [3, 1, 4, 6]], 1, 4, 6, 3)
# should be 10, but is 8

from collections import deque

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def wrong_solution(rectangle, characterX, characterY, itemX, itemY):
    visitable = [[True for _ in range(51)] for _ in range(51)]
    # 겹치면 이동 불가
    for rect in rectangle:
        [x1, y1, x2, y2] = rect
        for x in range(x1+1, x2):
            for y in range(y1+1, y2):
                visitable[x][y] = False
    # 테두리 이동 가능
    valid_path = set()
    for rect in rectangle:
        [x1, y1, x2, y2] = rect
        for x in range(x1, x2):
            valid_path.add((x, y1, x+1, y1))
            valid_path.add((x, y2, x+1, y2))
        for y in range(y1, y2):
            valid_path.add((x1, y, x1, y+1))
            valid_path.add((x2, y, x2, y+1))

    paths = deque([])
    paths.append([characterX, characterY, 0])
    print(visitable)
    while True:
        [cur_x, cur_y, d] = paths.popleft()
        visitable[cur_x][cur_y] = False
        for i in range(4):
            x = cur_x + dx[i]
            y = cur_y + dy[i]
            if x == itemX and y == itemY:
                return d+1
            if x < 0 or x >= 51: continue
            if y < 0 or y >= 51: continue
            if not visitable[x][y]: continue
            visitable[x][y] = True
            if ((cur_x, cur_y, x, y) in valid_path) or ((x, y, cur_x, cur_y) in valid_path):
                paths.append([x, y, d+1])
