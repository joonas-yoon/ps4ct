n = int(input())

dis = input().split()
pay = input().split()

ans = 0
min = int(pay[0])

for idx, distance in enumerate(dis):
    ans += int(distance)*min
    if min > int(pay[idx+1]) :
        min = int(pay[idx+1])
print(ans)