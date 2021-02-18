def toMin(s):
    h, m = map(int, s.split(':'))
    return h * 60 + m

def note2arr(notes, l):
    a = []
    ln = len(notes)
    for i in range(max(2 * l, ln)):
        o = notes[i % ln]
        if o == '#':
            a[-1] = a[-1].lower()
        else:
            a.append(o)
    if l != -1:
        return "".join(a[:l])
    return "".join(a)

def solution(m, infos):
    p = note2arr(m, -1)
    ans = []
    for i in range(len(infos)):
        start, end, name, notes = infos[i].split(',')
        _range = toMin(end) - toMin(start) + 1
        _notes = note2arr(notes, _range)
        if _notes.count(p) > 0:
            ans.append((-_range, i, name))

    if len(ans) == 0:
        return "(None)"

    return sorted(ans)[0][2]
