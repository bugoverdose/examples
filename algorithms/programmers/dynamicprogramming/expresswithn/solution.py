# https://school.programmers.co.kr/learn/courses/30/lessons/42895?language=python3

# 12 = 5 + 5 + (5 / 5) + (5 / 5)
# 12 = 55 / 5 + 5 / 5
# 12 = (55 + 5) / 5

def solution(N, number):
    combs = [[]]
    for count in range(1, 9):
        cur_combs = set([])
        for i in range(1, count):
            j = count - i
            for a in combs[i]:
                for b in combs[j]:
                    cur_combs.add(a + b)
                    cur_combs.add(a - b)
                    cur_combs.add(b - a)
                    cur_combs.add(a * b)
                    if a != 0:
                        cur_combs.add(int(b / a))
                    if b != 0:
                        cur_combs.add(int(a / b))
        cur_combs.add(int(str(N) * count))
        if number in cur_combs:
            return count
        combs.append(list(cur_combs))
    return -1

print(solution(5, 12))
print(solution(2, 11))

# ========================================================

def other_solution(N, number):
    combs = [[]]
    for count in range(1, 9):
        combs.append([int(str(N) * count)])
        for i in range(1, count):
            j = count - i
            for a in combs[i]:
                for b in combs[j]:
                    combs[count].append(a + b)
                    combs[count].append(a - b)
                    combs[count].append(b - a)
                    combs[count].append(a * b)
                    if a != 0:
                        combs[count].append(int(b / a))
                    if b != 0:
                        combs[count].append(int(a / b))
        combs[count] = list(set(combs[count]))
        if number in combs[count]:
            return count
    return -1
