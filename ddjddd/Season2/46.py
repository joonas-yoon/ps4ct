import bisect

table = dict()

def solution(info, query):
    answer = []

    for it in info:
        data = it.split(" ")
        score = int(data[-1])

        def make_key(key, index):
            if index == 4:
                if key not in table.keys():
                    table[key] = [score]
                else:
                    table[key].append(score)

                return key

            make_key(key+data[index], index+1)
            make_key(key+"-", index+1)

        make_key("", 0)

    for key in table.keys():
        table[key].sort()

    for it in query:
        cond = it.split(" ")
        score = int(cond[-1])
        cond = cond[0] + cond[2] + cond[4] + cond[6]
        if cond not in table.keys(): answer.append(0)
        else:
            dataLen = len(table[cond])
            ans = dataLen - bisect.bisect_left(table[cond], score, lo=0, hi=dataLen)
            answer.append(ans)

    return answer


ans = solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],
["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"])

print(ans)
# solution(["java backend junior pizza 150"],[])