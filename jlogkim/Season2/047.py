def valid(ch):
    if ch>='A' and ch<='Z':
        return ch.lower()
    
    if ch=='-' or ch=='_' or ch=='.' or (ch>='a' and ch<='z') or (ch>='0' and ch<='9'):
        return ch
    
    return ''

def solution(new_id):
    answer = ''
    print(new_id[0])
    length = 0
    
    for i in range(len(new_id)):
        if len(answer)>=15:
            break;
        alpha = valid(new_id[i])
        
        if alpha:
            if len(answer)==0 and alpha !='.':
                answer+=alpha
            elif len(answer)>0 and (alpha !='.' or answer[-1]!='.'):
                answer+=alpha
    if len(answer)==0:
        answer='a'
    elif answer[-1]=='.':
        answer=answer[0:-1]
    
    while len(answer)<=2:
        answer+=answer[-1]
        
    
            
    return answer