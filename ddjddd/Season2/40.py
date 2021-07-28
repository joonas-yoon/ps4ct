import sys

count = int(sys.stdin.readline())
sentences = sys.stdin.readline()[:-1]

if count <= 25:
    print(sentences)
else:
    tmp = sentences[11:-12]
    if '.' in tmp:
        print(sentences[:9] + "......" + sentences[-10:])
    else:
        print(sentences[:11] + "..." + sentences[-11:])
