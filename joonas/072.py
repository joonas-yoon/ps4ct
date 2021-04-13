def bal(c):
    return -1 if c == ')' else 1

def isBalanced(s):
    x = []
    for i in s:
        if i == '(': x.append(i)
        elif len(x) == 0: return False
        else: x.pop()
    return True


def flip(s):
    r = ''
    for i in s: r += '(' if i == ')' else ')'
    return r


def solution(s):
    if len(s) < 1: return ''    # 1
    b, i = bal(s[0]), 1
    l = len(s)
    while i < l and b != 0:
        b += bal(s[i])
        i += 1
    u, v = s[:i], s[i:]         # 2
    if isBalanced(u):
        return u + solution(v)  # 3-1
    r = '(' + solution(v) +')'  # 4-1~3
    r += flip(u[1:-1])          # 4-4~5
    return r