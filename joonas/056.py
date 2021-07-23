from math import ceil, log2

def f(k):
    b = 2 ** ceil(log2(k))
    print(b, 0 if k == b else 1+format(k, 'b').rindex('1'))

f(int(input()))
