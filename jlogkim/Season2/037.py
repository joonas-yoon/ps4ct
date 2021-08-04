def solution(s):
    ans=0
    dict={'zero':0,
          'one':1,
          'two':2,
          'three':3,
          'four':4,
          'five':5,
          'six':6,
          'seven':7,
          'eight':8,
          'nine':9
         }
    st=-1
    
    for idx, ch in enumerate(s):
        if ch<'0' or ch>'9':
            if st == -1:
                st=idx
            elif (idx-st+1)>=3 and s[st:idx+1] in dict:
                ans=ans*10+dict[s[st:idx+1]]
                st=-1                
        else:
            ans=ans*10+int(ch)

    
    return ans