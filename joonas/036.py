def solution(answers):
    p1 = [1, 2, 3, 4, 5]
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    cnt = [[0, 1], [0, 2], [0, 3]]
    for i in range(len(answers)):
        cnt[0][0] += p1[i % len(p1)] == answers[i]
        cnt[1][0] += p2[i % len(p2)] == answers[i]
        cnt[2][0] += p3[i % len(p3)] == answers[i]
    cnt = sorted(cnt)[::-1]
    answer = []
    for i in range(3):
        if cnt[0][0] == cnt[i][0]:
            answer.append(cnt[i][1])
    return sorted(answer)