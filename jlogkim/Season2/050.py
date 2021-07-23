def diff_height(lh, rh, target):
    left=lh
    right=rh
    tg=target
    if lh<=0:
        left+=11
    if rh<=1:
        right+=11
    if tg==0:
        tg+=11
        
    lshare=(left-1)//3
    lmod=(left-1)%3
    
    rshare=(right-1)//3
    rmod=(right-1)%3
    
    tshare=(tg-1)//3
    tmod=(tg-1)%3
    
    l=abs(tshare-lshare)+abs(tmod-lmod)
    r=abs(tshare-rshare)+abs(tmod-rmod)
    
    return l-r


def solution(numbers, hand):
    lh=-1 
    rh=1
    
    is_left=hand=='left'
        
    answer = ''
    
    larr=[1,4,7]
    rarr=[3,6,9]
    
    for i in numbers:
        if i in larr:
            answer+='L'
            lh=i
        elif i in rarr:
            answer+='R'
            rh=i
        else:
            res=diff_height(lh, rh, i)
            if res>0:
                answer+='R'
                rh=i
            elif res<0:
                answer+='L'
                lh=i
            elif is_left:
                answer+='L'
                lh=i
            else:
                answer+='R'
                rh=i
            
    return answer