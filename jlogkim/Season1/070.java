public class Solution {
    public int maxProduct(int[] nums) {
        int pos=0;
        int max;
        int neg=0;
        int num=nums[0];
        max=num;
        if(num>0)pos=num;
        else if(num<0)neg=num;
        int pp;
        int pn;
        int ans=max;
        //System.out.println(pos+" "+neg+"  :"+max);
        for(int i=1;i<nums.length;i++){
            num=nums[i];
            if(num>0){
                if(pos>0){pos*=num;}
                else if(pos==0){pos=num;}
                if(neg<0){neg*=num;}
            }
            if(num<0){
                pn=0;
                pp=0;
                if(pos>0)pn=pos*num;
                else if(pos==0)pn=num;
                if(neg<0)pp=neg*num;
                pos=pp;
                neg=pn;
            }
            if(num==0){
                pos=0;
                neg=0;
            }
            
            max=Math.max(pos,num);
            //System.out.println(pos+" "+neg+"  :"+max);
            if(max>ans)ans=max;
        }
        return ans;
    }
}class 070 {
    
}
