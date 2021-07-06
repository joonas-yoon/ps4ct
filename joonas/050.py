def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def f(l, r, c, hand):
    dl, dr = dist(l, c), dist(r, c)
    if dl == dr:
        return 'L' if hand == "left" else 'R'
    return 'L' if dl < dr else 'R'

def solution(numbers, hand):
    pos = [(3,1)] + [(i // 3, i % 3) for i in range(0, 9)]
    l, r = (3,0), (3,2)
    answer = ''
    
    for n in numbers:
        if n in [1,4,7]:
            h = 'L'
        elif n in [3,6,9]:
            h = 'R'
        else:
            h = f(l, r, pos[n], hand)

        answer += h
        print(n, dist(pos[n], l), dist(pos[n], r), h)
        if h == 'L':
            l = pos[n]
        else:
            r = pos[n]

    return answer