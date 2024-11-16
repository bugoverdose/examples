# 백준 집합 문제(https://www.acmicpc.net/problem/11723) - boj/11723.py 참고

# 작은 범위의 정수로 이루어진 집합 S에 적용하기 적합
# - 최대 n개의 원소
# - 원소 x (0 <= x < n)
# - 각 비트는 특정 원소의 포함 여부를 의미 => i번째 비트가 1이면 i가 집합에 포함됨
# n비트만 필요하므로 메모리 사용량 최소화
S = 0
n = 20

# 원소 추가: 특정 비트를 1로 설정
def add(x):
    global S
    S |= 1 << x # OR 연산

# 원소 제거: 특정 비트를 0으로 설정
def remove(x):
    global S
    S &= ~(1 << x) # AND NOT 연산

# 원소 토글: 특정 비트가 0이면 1로, 1이면 0으로 설정
def toggle(x):
    global S
    S ^= 1 << x # XOR 연산

# 원소 검사: 특정 비트가 1인지 확인
def exists(x):
    global S
    return (S & (1 << x)) > 0 # AND 연산

# 집합 초기화 : 모든 비트에 0 할당
def reset():
    global S
    S = 0

# 모든 비트에 1 할당
def all():
    global S
    S = (1 << (n+1)) - 1

print(bin(S)[2:]) # 0
all()
print(bin(S)[2:]) # 111111111111111111111
reset()
print(bin(S)[2:]) # 0
add(20)
add(0)
add(3)
add(3)
print(bin(S)[2:]) # 100000000000000001001
print(exists(3)) # True
remove(3)
remove(3)
print(bin(S)[2:]) # 100000000000000000001
print(exists(3)) # False
toggle(3)
print(bin(S)[2:]) # 100000000000000001001

# =======================================================
# 집합 연산

# 합집합: OR 연산
def union(set1, set2):
    return set1 | set2

# 교집합: AND 연산
def intersection(set1, set2):
    return set1 & set2

# 차집합: AND NOT 연산
def difference(set1, set2):
    return set1 & ~set2

A = 0b1101
B = 0b0111

print(bin(union(A, B))[2:]) # 1111
print(bin(intersection(A, B))[2:]) # 0101
print(bin(difference(A, B))[2:]) # 1000
print(bin(difference(B, A))[2:]) # 0010
