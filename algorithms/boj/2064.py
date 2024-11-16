# [비트마스크] IP 주소 https://www.acmicpc.net/problem/2064

import sys

input = sys.stdin.readline

N = int(input())
ips = [0] * N

for i in range(N):
    a,b,c,d = map(int, input().split("."))
    ip = d
    ip += (c << 8)
    ip += (b << 16)
    ip += (a << 24)
    ips[i] = ip

raw = ips[0]
m = 32

for cur_m in range(32):
    all_same = True
    prev = ips[0] >> cur_m
    for i in range(1, N):
        cur = ips[i] >> cur_m
        if prev & cur != cur:
            all_same = False
            break
        prev = cur
    if all_same:
        m = cur_m
        break

def print_ip_format(bits):
    ip = str((bits >> 24) & 255) + "."
    ip += str((bits >> 16) & 255) + "."
    ip += str((bits >> 8) & 255) + "."
    ip += str(bits & 255)
    print(ip)

print_ip_format((raw >> m) << m) # address
print_ip_format((0b11111111_11111111_11111111_11111111 >> m) << m) # mask


# 입력
# 3
# 194.85.160.177
# 194.85.160.183
# 194.85.160.178

# 출력
# 194.85.160.176
# 255.255.255.248
