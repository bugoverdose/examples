# 최하위 비트 찾기 (Least Significant Bit, LSB)
# 정수에서 가장 오른쪽에 있는 1의 위치를 찾는 방법입니다. 이 방법은 주로 특정 비트가 설정된 위치를 확인할 때 사용됩니다.

# LSB 찾기: x & -x => 최하위 1 비트만 남긴 값
# LSB 위치: (x & -x).bit_length() - 1 => 1의 위치 확인

x = 12
lsb = x & (~x + 1) 
lsb = x & -x # 동일
lsb_idx = lsb.bit_length() - 1

print(bin(x)[2:]) # 1100
print(bin(lsb)[2:]) # 100
print(lsb_idx) # 2

# 핵심: -x = ~x + 1

# x = 1100
# ~x = 0011
# -x = ~x + 1 = 0100
# x & -x = 1100 & 0100 = 100

# ======================================================

# 최상위 비트 찾기 (Most Significant Bit, MSB)
# 정수에서 가장 왼쪽에 있는 1의 위치를 찾는 방법.
# 정수의 크기나 범위를 빠르게 계산할 때 유용.

# 핵심: shift 연산으로 2씩 나누는 작업을 0이 될때까지 반복한 횟수

def msb_position(x):
    pos = 0
    while x > 1:
        x >>= 1
        pos += 1
    return pos

print(bin(18)[2:]) # 10010 
print(msb_position(18)) # 4
