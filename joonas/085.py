def toMin(s):
    h, m = map(int, s.split(':'))
    return h * 60 + m

def note2arr(notes, l):
    a = []
    ln = len(notes)
    for i in range(max(2 * l, ln)):
        o = notes[i % ln]
        if o == '#':
            a[-1] += 1
        else:
            a.append(2 * (ord(o) - ord('A')))
    if l != -1:
        return a[:l]
    return a

# s: string, p: pattern
def isMatched(s, p):
    if len(p) > len(s): return False
    for i in range(len(s)):
        j = 0
        while j < len(p) and i + j < len(s):
            if s[i+j] != p[j]: break
            j += 1
        if j == len(p):
            return True
    return False

def solution(m, infos):
    p = note2arr(m, -1)
    ans = []
    for i in range(len(infos)):
        start, end, name, notes = infos[i].split(',')
        _range = toMin(end) - toMin(start) + 1
        _notes = note2arr(notes, _range)
        if isMatched(_notes, p):
            ans.append((-_range, i, name))

    if len(ans) == 0:
        return "(None)"

    return sorted(ans)[0][2]
