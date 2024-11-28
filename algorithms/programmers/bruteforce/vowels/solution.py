# https://school.programmers.co.kr/learn/courses/30/lessons/84512?language=python3

def solution(word):
    vowels = ["A", "E", "I", "O", "U"]
    target = []
    for w in word:
        target.append(w)

    answer = 1
    cur = ["A"]
    while target != cur:
        answer += 1
        if len(cur) < 5:
            cur.append("A")
            continue
        while len(cur) >= 2 and cur[-1] == "U":
            cur.pop()
        for i in range(4):
            if cur[-1] == vowels[i]:
                cur[-1] = vowels[i+1]
                break
    return answer

print(solution("AAAAE")) # 6
print(solution("AAAE")) # 10
print(solution("I")) # 1563
print(solution("EIO")) # 1189
