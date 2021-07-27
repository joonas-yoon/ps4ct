def solve(s):
    if len(s) <= 25: return s
    p = s[11:-11]
    for x in s.split('.')[:-1]:
        if (x + '.').find(p) != -1:
            return s[:11] + '...' + s[-11:]
    return s[:9] + '......' + s[-10:]

n = int(input())
s = input()
print(solve(s))
