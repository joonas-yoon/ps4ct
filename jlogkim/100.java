class Solution {
    
    public int[][] progation_way= {{1,0},{0,1},{-1,-1}};
    public int[] solution(int n) {
        int size = (n+1)*n/2;
        int[] answer = new int[size];

        int x=0;
        int y=1;
        int now = 1;
        for(int i = n; i > 0; i--){
            
            int prog = (n - i)%3;
            int pror = progation_way[prog][0];
            int proc = progation_way[prog][1];
            
            for(int j = 0; j < i ; j++){
                x += pror;
                y += proc;
                int index = (x)*(x-1)/2 + y -1 ;
                answer[index]=now++;   
            }
            
            
        }
        
        return answer;
    }
}