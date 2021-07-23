def solution(a):
    size=len(a)
    lmin=a[0]
    left_min=[lmin]
    rmin=a[size-1]
    right_min=[rmin]
    
    for idx in range(1, size):
        if a[idx]<lmin:
            lmin=a[idx]
        left_min.append(lmin)
        if a[size-1-idx]<rmin:
            rmin=a[size-1-idx]
        right_min.append(rmin)
    
    
    ans=0
    for idx in range(0,size):
        if idx==0 or idx==(size-1):
            ans+=1
        elif left_min[idx-1]>= a[idx] or right_min[size-2-idx]>=a[idx]:
            ans+=1
            
    
    return ans