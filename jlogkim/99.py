class value {
    int total=0;
    int last=0;
    String pre="";
    String child="";
    int targetlength;

    public value(int targetlength){
        this.targetlength = targetlength;
    }

    public int insertChar(char targetchar,int targetlength){
        if(this.targetlength!=targetlength){
            System.out.println("target length different");
        }
        this.child+=targetchar;
        total++;

        if(child.length()>=targetlength){
            if(pre!=""&&pre.equals(child)){
                total-=targetlength;
                if(last==1||last==9||last==99||last==999){
                    total++;
                }
                last++;
                child="";
            }else{
                pre=child;
                child="";
                last=1;
            }
        }
        return total;
    }
}

class Solution {
    public int solution(String s) {
        int length = s.length();
        int max_prt = length/2;
        value[] memory = new value[max_prt];

        for(int i=0; i<max_prt; i++){
            memory[i]= new value(i+1);
        }

        for(int p = 1; p <= length; p++){
            for(int tl = 1; tl<=max_prt; tl++){
                memory[tl-1].insertChar(s.charAt(p-1),tl);
            }
        }
        int answer = length;
        for(int tl = 1; tl<=max_prt; tl++){
            if(answer>memory[tl-1].total){
                answer = memory[tl-1].total;
            }
        }
        
        return answer;
    }
}