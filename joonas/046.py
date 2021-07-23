from bisect import bisect_left as lower_bound

def solution(info, query):
    x = {}
    for i in info:
        a = i.split()
        key = a[0][0] + a[1][0] + a[2][1] + a[3][1]
        if not key in x: x[key] = []
        x[key].append(int(a[4]))

    for (key, arr) in x.items():
        arr.sort()
    
    answer = []
    for _q in query:
        q = list(map(lambda x:x.strip(), _q.split("and")))
        q[-1], score = q[-1].split()
        a = "cjp" if q[0] == '-' else q[0][0]
        b = "bf" if q[1] == '-' else q[1][0]
        c = "ue" if q[2] == '-' else q[2][1]
        d = "hi" if q[3] == '-' else q[3][1]
        a, b, c, d = map(list, [a, b, c, d])
        score = int(score)

        cnt = 0
        for a0 in a:
            for b0 in b:
                for c0 in c:
                    for d0 in d:
                        key = a0+b0+c0+d0
                        if not key in x: continue
                        arr = x[key]
                        cnt += len(arr) - lower_bound(arr, score)
        answer.append(cnt)
        
    return answer