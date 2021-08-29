public class Solution {
    
    public boolean isInterleave(String s1, String s2, String s3) {
        Queue<Integer> queue = new LinkedList<Integer>();
        
        //boolean isPossibleS1[] = new boolean [s1.length()+1];
        // initialize 
        //isPossibleS1[0]=true;
        queue.offer(0);
        
        boolean isPossible[] = new boolean [s1.length()+1];
        if(s3.length()!=(s1.length()+s2.length())) return false;
        // number of s2 to get 
        int s1_numb, s2_numb;
        
        for(int point=0; point<s3.length(); point++){
            while(!queue.isEmpty()){
                s1_numb=queue.poll();
                s2_numb=point-s1_numb;
                if((s1_numb+1)<=s1.length()&&s1.charAt(s1_numb)==s3.charAt(point))                              isPossible[s1_numb+1]=true;
                if((s2_numb+1)<=s2.length()&&s2.charAt(s2_numb)==s3.charAt(point))
                    isPossible[s1_numb]=true;
            }

            for(int idx=0;idx<=s1.length();idx++){
                if(isPossible[idx])queue.offer(idx);
                isPossible[idx]=false;
            }
        }

        if(queue.size()>0) return true;
        else return false;
        
    }
}class 034 {
    
}
