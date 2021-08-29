a = [1,2,3,4,5]
b = [2,1,2,3,2,4,2,5]
c = [3,3,1,1,2,2,4,4,5,5]

def solution(answers):
    ac = 0
    bc = 0
    cc = 0
    for i in range(0, len(answers)):
        ac += 1 if a[i%5] == answers[i] else 0
        bc += 1 if b[i%8] == answers[i] else 0
        cc += 1 if c[i%10] == answers[i] else 0

    mc = max(ac, bc, cc)
    answer = []
    idx = 1
    print(mc)
    for ta in [ac, bc, cc]:
        if ta == mc:
            answer.append(idx)
        idx += 1


    return answer