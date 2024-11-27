# https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=python3

def solution(string):
    opens = 0
    for s in string:
        opens += (1 if s == "(" else -1)
        if opens < 0: return False
    return opens == 0
