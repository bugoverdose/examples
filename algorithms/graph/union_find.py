parents = [0, 1, 2, 3, 4, 5]

def find(a):
    global parents
    if parents[a] == a:
        return a
    parents[a] = find(parents[a]) # 갱신
    return parents[a]

def union(a, b):
    global parents
    pa = find(a)
    pb = find(b)
    if pa > pb:
        pa, pb = pb, pa
    parents[pb] = pa # 부모를 갱신
    # 주의: 자녀들의 부모 갱신 필요

def refresh_parents():
    global parents
    for i in range(len(parents)):
        find(i)

print(parents) # [0, 1, 2, 3, 4, 5]

union(1, 3)
print(find(1)) # 1
print(find(3)) # 1
print(parents) # [0, 1, 2, 1, 4, 5]

union(2, 4)
print(parents) # [0, 1, 2, 1, 2, 5]
union(3, 4)
print(parents) # [0, 1, 1, 1, 2, 5]
refresh_parents()
print(parents) # [0, 1, 1, 1, 1, 5]
