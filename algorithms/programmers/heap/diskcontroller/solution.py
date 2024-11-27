# https://school.programmers.co.kr/learn/courses/30/lessons/42626?language=python3

# 작업의 소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것 순으로 우선순위가 높습니다.
# 모든 요청 작업의 반환 시간의 평균의 정수부분을 return 

from heapq import heappush, heappop

def solution(jobs):
    answer = 0

    new_jobs = []
    for i in range(len(jobs)):
        new_jobs.append([i, jobs[i][0], jobs[i][1]])
    jobs = new_jobs
    jobs.sort(key = lambda x:x[1])

    time = 0
    job_idx = 0
    q = []
    while job_idx < len(jobs) or q:
        while job_idx < len(jobs):
            [job_id, req_time, required_time] = jobs[job_idx]
            if time < req_time: break
            heappush(q, (required_time, req_time, job_id))
            job_idx += 1
        if not q:
            time += 1
            continue
        (required, req, _) = heappop(q)
        time += required
        answer += time - req
    return answer // len(jobs)

print(solution([[0, 3], [1, 9], [3, 5]])) # 8
print(solution([[0, 3], [1, 10], [3, 5]])) # 8
print(solution([[0, 3], [1, 11], [3, 5]])) # 8
