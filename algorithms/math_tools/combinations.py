from itertools import combinations
from math import factorial

# 조합

print(list(combinations(["A", "B", "C"], 0)))
# [()]
print(list(combinations(["A", "B", "C"], 1)))
# [('A',), ('B',), ('C',)]
print(list(combinations(["A", "B", "C"], 2)))
# [('A', 'B'), ('A', 'C'), ('B', 'C')]
print(list(combinations(["A", "B", "C"], 3)))
# [('A', 'B', 'C')]

# =========================================

# 조합의 크기
# nCr = n! / ( (n-r)! * (r)! )
n = 5
r = 3
print(factorial(n) // factorial(n-r) // factorial(r)) 
# 10

print(list(combinations(["A", "B", "C", "D", "E"], 3)))
# [('A', 'B', 'C'), ('A', 'B', 'D'), ('A', 'B', 'E'), ('A', 'C', 'D'), ('A', 'C', 'E'), ('A', 'D', 'E'), ('B', 'C', 'D'), ('B', 'C', 'E'), ('B', 'D', 'E'), ('C', 'D', 'E')]
print(len(list(combinations(["A", "B", "C", "D", "E"], 3)))) 
# 10
