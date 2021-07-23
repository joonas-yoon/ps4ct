import re


def solution(new_id):
    new_id = new_id.lower()

    new_id = re.sub('[^a-z0-9-_.]', '', new_id)

    target = new_id.replace("..", ".")
    while target != new_id:
        new_id = target
        target = new_id.replace("..", ".")

    new_id = target

    if len(new_id) > 0 and new_id[0] == '.':
        new_id = new_id[1:]
    if len(new_id) > 0 and new_id[-1] == '.':
        new_id = new_id[:-1]

    if len(new_id) == 0:
        new_id = "a"
    if len(new_id) > 15:
        new_id = new_id[:15]
    if new_id[-1] == '.':
        new_id = new_id[:-1]

    a = new_id[-1]
    while len(new_id) <= 2:
        new_id += a

    return new_id


print(solution("...!@BaT#*..y.abcdefghijklm"	))
print(solution("z-+.^."))
print(solution("=.="))
print(solution("123_.def"	))
print(solution("abcdefghijklmn.p"	))

# "bat.y.abcdefghi"
# "z--"
# "aaa"
# "123_.def"
# "abcdefghijklmn"