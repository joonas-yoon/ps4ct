import re

def solution(s):
    s = re.sub(r'[^-_\.0-9a-z]+', '', s.lower())
    s = re.sub(r'\.{2,}', '.', s)
    if len(s) > 0 and s[0] == '.': s = s[1:]
    if len(s) > 0 and s[-1] == '.': s = s[:-1]
    if len(s) == 0: s = "a"
    elif len(s) >= 16: s = s[:15]
    if len(s) > 0 and s[-1] == '.': s = s[:-1]
    if len(s) < 3: s += s[-1] * (3-len(s))
    return s