def solution(s):
    answer = -1

    st = []
    
    for ch in s:
        if len(st)>0 and st[-1]== ch:
            st.pop()
        else:
            st.append(ch)

    if len(st)==0:
        return 1
    else:
        return 0