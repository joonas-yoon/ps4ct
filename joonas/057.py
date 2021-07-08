h, m = map(int, input().split())
M = 24 * 60
t = (h * 60 + m - 45 + M) % M
print(t // 60, t % 60)
