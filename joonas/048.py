from math import inf

def solution(a):
    n = len(a)
    if n < 3: return n
    
    l = [0 for i in range(n)]
    r = [0 for i in range(n)]
    l[0], r[n-1] = inf, inf
    for i in range(1, n):
        l[i] = min(l[i-1], a[i-1])
    for i in range(n-2, -1, -1):
        r[i] = min(r[i+1], a[i+1])

    answer = 2
    for i in range(1, n-1):
        answer += 0 if l[i] < a[i] > r[i] else 1
    return answer