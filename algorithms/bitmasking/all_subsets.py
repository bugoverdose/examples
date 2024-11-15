elements = ['a', 'b', 'c']
n = len(elements)

# 2^n가지 모든 부분집합들 생성 - (0,0,0), (0,0,1), (0,1,0), (0,1,1), ...
for i in range(1 << n): 
    subset = []
    for j in range(n):
        if i & (1 << j):
            subset.append(elements[j])
    print(bin(i)[2:], subset)

# 0 []
# 1 ['a']
# 10 ['b']
# 11 ['a', 'b']
# 100 ['c']
# 101 ['a', 'c']
# 110 ['b', 'c']
# 111 ['a', 'b', 'c']
