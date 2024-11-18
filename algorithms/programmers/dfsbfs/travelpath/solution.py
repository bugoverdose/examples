# https://school.programmers.co.kr/learn/courses/30/lessons/43164

# 주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.
# 항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

# 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
# 주어진 공항 수는 3개 이상 10,000개 이하입니다.
# tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
# 주어진 항공권은 모두 사용해야 합니다.
# 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.

def dfs():
    global visited, path, t_dic, answer
    if len(path) == len(visited) + 1:
        answer = list(path)
        return
    if len(path) == 0:
        return
    cur = path[-1]
    if cur not in t_dic:
        return # 티켓이 전혀 없으므로 순회 불가
    for t in t_dic[cur]:
        (to, i) = t
        if visited[i]: continue
        visited[i] = True
        path.append(to)
        dfs()
        if answer != None: return
        path.pop()
        visited[i] = False

def solution(tickets):
    global visited, path, t_dic, answer
    N = len(tickets)
    visited = [False] * N
    path = ["ICN"]
    answer = None

    t_dic = {}
    for i in range(N):
        from_, to = tickets[i][0], tickets[i][1]
        if from_ not in t_dic:
            t_dic[from_] = []
        t_dic[from_].append((to, i))
    for from_ in t_dic.keys():
        t_dic[from_] = sorted(t_dic[from_])

    dfs()
    return answer

print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))
# ['ICN', 'JFK', 'HND', 'IAD']

print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]))
# ['ICN', 'ATL', 'ICN', 'SFO', 'ATL', 'SFO']

print(solution([["ICN", "AAA"], ["ICN", "BBB"], ["ICN", "CCC"], ["CCC", "ICN"], ["BBB", "ICN"]]))
# ['ICN', 'BBB', 'ICN', 'CCC', 'ICN', 'AAA']
