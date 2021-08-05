def solution(s):
    num = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    for i in range(10):
        s = s.replace(num[i], chr(ord('0') + i))
    return int(s)