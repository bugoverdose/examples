# https://school.programmers.co.kr/learn/courses/30/lessons/42583?language=python3

# 트럭 여러 대가 강을 가로지르는 일차선 다리를 정해진 순으로 건너려 합니다. 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 
# 다리에는 트럭이 최대 bridge_length대 올라갈 수 있으며, 다리는 weight 이하까지의 무게를 견딜 수 있습니다. 
# 단, 다리에 완전히 오르지 않은 트럭의 무게는 무시합니다.

from collections import deque

def solution(bridge_length, weight, truck_weights):
    bridge = deque([0 for _ in range(bridge_length)])
    total_weight = 0
    trucks = deque(truck_weights)
    time = 0

    while total_weight > 0 or trucks:
        time += 1
        total_weight -= bridge.popleft()
        if trucks and trucks[0] + total_weight <= weight:
            on_truck = trucks.popleft()
            bridge.append(on_truck)
            total_weight += on_truck
        else:
            bridge.append(0)
    return time

print(solution(2, 10, [7,4,5,6])) # 8
print(solution(100, 100, [10])) # 101
print(solution(100, 100, [10,10,10,10,10,10,10,10,10,10])) # 110
