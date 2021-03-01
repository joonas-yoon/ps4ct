import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
       int answer = 0;
        int n = board.length;
        int ind[] = new int[n];
        int i;
        for(int c=0;c<n;c++) {
	        for(i=0;i<n;i++) {
	        	if(board[i][c]>0) break;
	        } ind[c]=i;
	        System.out.print(ind[c]+" ");
        }
        System.out.println();
        Stack<Integer> stack=new Stack<Integer>();
        
        int totalmove = moves.length;
        int targetc;
        for( i=0; i<totalmove; i++) {
        	targetc=moves[i]-1;
        	if(ind[targetc]<n) {
        		if(!stack.isEmpty()&&stack.peek()==board[ind[targetc]][targetc]) {
        			answer+=2;
        			stack.pop();
        		}else {
        			stack.push(board[ind[targetc]][targetc]);
        		}
        		ind[moves[i]-1]++;
        	}
        }
        
        return answer;
    }
}