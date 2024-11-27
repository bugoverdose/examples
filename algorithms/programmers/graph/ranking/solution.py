# https://school.programmers.co.kr/learn/courses/30/lessons/49191?language=python3

from collections import deque

def solution(n, results):
    win_edges = {}
    lose_edges = {}
    for i in range(1, n+1):
        win_edges[i] = []
        lose_edges[i] = []
    for r in results:
        [w, l] = r
        win_edges[w].append(l)
        lose_edges[l].append(w)

    answer = 0
    for node in range(1, n+1):
        winners = set()
        losers = set()

        q = deque([node])
        while q:
            cur = q.popleft()
            for next_ in win_edges[cur]:
                if next_ not in winners:
                    winners.add(next_)
                    q.append(next_)

        q = deque([node])
        while q:
            cur = q.popleft()
            for next_ in lose_edges[cur]:
                if next_ not in losers:
                    losers.add(next_)
                    q.append(next_)

        if len(winners) + len(losers) == n - 1:
            answer += 1
    return answer

print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]])) # 2
# 2번 선수는 [1, 3, 4] 선수에게 패배했고 5번 선수에게 승리했기 때문에 4위입니다.
# 5번 선수는 4위인 2번 선수에게 패배했기 때문에 5위입니다.
