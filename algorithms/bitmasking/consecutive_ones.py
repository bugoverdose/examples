# Brian Kernighan’s Algorithm

# x & (x - 1)

# 정수의 이진 표현에서 1의 개수를 빠르게 세기 위해 개발된 알고리즘
# 주어진 수에서 1의 비트를 반복적으로 제거하여, 1의 비트 수를 세는 효율적인 방법을 제공
# 해당 알고리즘의 핵심은 x & (x - 1) 연산을 사용하여 가장 오른쪽에 있는 1을 매 반복마다 제거하는 것

def maxConsecutiveOnes(n):
    raw = n
    length = 0

    while n != 0:
        n = n & (n << 1)
        length += 1

    return f"{raw} [{bin(raw)[2:]}] => {length}"

for num in [0, 9, 13, 15,21, 30, 103, 111]:
    print(maxConsecutiveOnes(num))

# 0 [0] => 0
# 9 [1001] => 1
# 13 [1101] => 2
# 15 [1111] => 4
# 21 [10101] => 1
# 30 [11110] => 4
# 103 [1100111] => 3
# 111 [1101111] => 4
