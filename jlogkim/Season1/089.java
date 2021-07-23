class Solution {
	Integer countDigit[]=new Integer[20];
	Integer pow3[]=new Integer[20];
    
    public String get124(int n, int digit){
        if(digit==1){
            if(n==1)return "1";
            else if(n==2)return "2";
            else return "4";
        }
        int numb=1;
        while(n>(pow3[digit-1])){
            numb*=2;
            n-=pow3[digit-1];
        }
        
        return Integer.toString(numb)+get124(n,digit-1);
    }
    
    public String solution(int n) {
        String answer = "";
        int target = 1;
        int digit=0;
        int next=n;
        
        for(int i=1; i<20; i++){
            target*=3;
            pow3[i]=target;
            if(next>pow3[i]) {
            	next-=pow3[i];
            }else {
            	digit=i;
            	break;
            }
        }
        
        
        return get124(next, digit);
    }
}