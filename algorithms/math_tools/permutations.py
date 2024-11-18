from itertools import permutations
from math import factorial

# 순열

print(list(permutations(["A", "B", "C"], 0)))
# [()]
print(list(permutations(["A", "B", "C"], 1)))
# [('A',), ('B',), ('C',)]
print(list(permutations(["A", "B", "C"], 2)))
# [('A', 'B'), ('A', 'C'), ('B', 'A'), ('B', 'C'), ('C', 'A'), ('C', 'B')]
print(list(permutations(["A", "B", "C"], 3)))
# [('A', 'B', 'C'), ('A', 'C', 'B'), ('B', 'A', 'C'), ('B', 'C', 'A'), ('C', 'A', 'B'), ('C', 'B', 'A')]

# =========================================

# 순열의 크기
# nPr = (n)! / (n-r)!
n = 5
r = 3
print(factorial(n) // factorial(n-r))
# 60

print(list(permutations(["A", "B", "C", "D", "E"], 3)))
# [('A', 'B', 'C'), ('A', 'B', 'D'), ('A', 'B', 'E'), ('A', 'C', 'B'), ('A', 'C', 'D'), ('A', 'C', 'E'), ('A', 'D', 'B'), ('A', 'D', 'C'), ('A', 'D', 'E'), ('A', 'E', 'B'), ('A', 'E', 'C'), ('A', 'E', 'D'), ('B', 'A', 'C'), ('B', 'A', 'D'), ('B', 'A', 'E'), ('B', 'C', 'A'), ('B', 'C', 'D'), ('B', 'C', 'E'), ('B', 'D', 'A'), ('B', 'D', 'C'), ('B', 'D', 'E'), ('B', 'E', 'A'), ('B', 'E', 'C'), ('B', 'E', 'D'), ('C', 'A', 'B'), ('C', 'A', 'D'), ('C', 'A', 'E'), ('C', 'B', 'A'), ('C', 'B', 'D'), ('C', 'B', 'E'), ('C', 'D', 'A'), ('C', 'D', 'B'), ('C', 'D', 'E'), ('C', 'E', 'A'), ('C', 'E', 'B'), ('C', 'E', 'D'), ('D', 'A', 'B'), ('D', 'A', 'C'), ('D', 'A', 'E'), ('D', 'B', 'A'), ('D', 'B', 'C'), ('D', 'B', 'E'), ('D', 'C', 'A'), ('D', 'C', 'B'), ('D', 'C', 'E'), ('D', 'E', 'A'), ('D', 'E', 'B'), ('D', 'E', 'C'), ('E', 'A', 'B'), ('E', 'A', 'C'), ('E', 'A', 'D'), ('E', 'B', 'A'), ('E', 'B', 'C'), ('E', 'B', 'D'), ('E', 'C', 'A'), ('E', 'C', 'B'), ('E', 'C', 'D'), ('E', 'D', 'A'), ('E', 'D', 'B'), ('E', 'D', 'C')]
print(len(list(permutations(["A", "B", "C", "D", "E"], 3)))) 
# 60
