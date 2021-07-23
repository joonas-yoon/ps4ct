def isBalance(p):
    a, b = 0, 0
    for i in p:
        if i == "(":
            a += 1
        elif i == ")":
            b += 1
    return a == b


def isCorrect(p):
    stack = 0
    for i in p:
        if i == "(":
            stack += 1
        elif i == ")":
            stack -= 1

        if stack < 0:
            return False

    return stack == 0


def solution(p):
    answer = ""

    if isCorrect(p):
        return p

    plen, mlen = 2, len(p)

    if mlen == 0:
        return ""

    for i in range(plen, mlen + 1, 2):
        u, v = p[:i], p[i:]
        if isBalance(u):
            break

    if isCorrect(u):
        answer = u + solution(v)
    else:
        u = u[1:-1]
        nu = ""
        for j in u:
            if j == "(":
                nu += ")"
            elif j == ")":
                nu += "("
        answer = "(" + solution(v) + ")" + nu

    return answer