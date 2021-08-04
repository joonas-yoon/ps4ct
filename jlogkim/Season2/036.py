def solution(answers):
    score = [0,0,0]
    
    rule=[[1,2,3,4,5],
          [2,1,2,3,2,4,2,5],
          [3,3,1,1,2,2,4,4,5,5]]
    
    idx=[0,0,0]
              
    for ans in answers:
        for i in range(3):
            if rule[i][idx[i]] == ans:
                score[i]=score[i]+1
            idx[i]=((idx[i]+1)%len(rule[i]))

    mx= max(score)
    answer = []
    for i in range(3):
        if score[i]==mx:
            answer.append(i+1)

    return answer