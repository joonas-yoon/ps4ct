import itertools


def solution(orders, course):
    answer = []

    for plen in course:
        rlist = []
        for k in orders:
            tmp = [j for j in k]
            tmp.sort()
            rlist += list(itertools.combinations(tmp, plen))

        cnt_max = 0

        t_answer = []
        for i in list(set(rlist)):
            tmp = rlist.count(i)
            if tmp >= 2:
                ret = "".join(i)

                if tmp > cnt_max:
                    t_answer = [ret]
                    cnt_max = tmp
                elif tmp == cnt_max:
                    t_answer.append(ret)

        answer += t_answer

    answer.sort()

    return answer