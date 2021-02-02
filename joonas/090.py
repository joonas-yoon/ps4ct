# return: (start, end)
def toInterval(s):
    ymd, t, ms = s.split()
    t = t.split(':')
    ret = int(t[0])
    ret = ret * 60 + int(t[1])
    ret = ret * 60 + float(t[2]) + 1e-8
    a, b = ret - float(ms[:-1]), ret
    return (int(a * 1000 + 1), int(b * 1000))


def solution(lines):
    a = []
    for i in range(len(lines)):
        a.append(toInterval(lines[i]))
    a.sort()

    def intersect(s, e, y):
        if y[0] <= s and e <= y[1]: return 1
        return 1 if s <= y[0] <= e or s <= y[1] <= e else 0

    ans = 0
    for x in a:
        c1, c2, c3, c4 = 0, 0, 0, 0
        for y in a:
            c1 += intersect(x[0], x[0] + 999, y)
            c2 += intersect(x[0] - 999, x[0], y)
            c3 += intersect(x[1], x[1] + 999, y)
            c4 += intersect(x[1] - 999, x[1], y)
        ans = max(ans, c1, c2, c3, c4)
            
    return ans
