def solution(n):
    k = 1
    a = []
    while n >= k:
        n -= k
        a.insert(0, 2 ** ((n % (3 * k)) // k))
        k *= 3
    return ''.join(map(str, a))
