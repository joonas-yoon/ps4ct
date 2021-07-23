dict_arr =[{'base':8, 'cpp': 0,'java':1, 'python':2},{'base':4,'backend':0,'frontend':1},{'base':2,'junior':0, 'senior':1}, {'base':1,'chicken':0, 'pizza':1}]

def is_in(target, req_arr):
    for idx in range(4):
        t=int(target/dict_arr[idx]['base'])
        target%=int(dict_arr[idx]['base'])
        if req_arr[idx]!='-' and t!= dict_arr[idx][req_arr[idx]]:
            return False
    return True

                    

def solution(info, query):
    grade = [[],[],[],[],[],[],[],[],
           [],[],[],[],[],[],[],[],
           [],[],[],[],[],[],[],[]]
    
    for str in info:
        numb=0
        str_arr = str.split()
        for idx in range(4):
            value =  str_arr[idx]
            numb*=2
            numb+=dict_arr[idx][value]
        grade[numb].append(int(str_arr[4]))

    for idx in range(24):
        grade[idx].sort()
        
    answer = []
    for idx, req in enumerate(query):
        ans=0
        req=req.replace("and","")
        req_arr = req.split()
        target_score=int(req_arr[-1])
        for q_idx in range(24):
            if is_in(q_idx,req_arr) and len(grade[q_idx])>0:
                st=0
                ed=len(grade[q_idx])-1
                while st<=ed:
                    mid=int((st+ed)/2)
                    if grade[q_idx][mid] < target_score:
                        st=mid+1
                    else:
                        ed=mid-1
                        
                ans+=len(grade[q_idx])-st

        answer.append(ans)  
            

    
    return answer