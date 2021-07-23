class Solution {
    boolean visit[][];
    char[][] sol_board;
    int way[][] = {{1,0},{-1,0},{0,1},{0,-1}};
    String target;
    private boolean hasWord(int i,int j,int bef){
        int nr,nc;
        if((bef+1)>=target.length()) return true;
        for(int idx=0; idx<4; idx++){
            nr=i+way[idx][0];
            nc=j+way[idx][1];
            if(nr>=0&&nr<sol_board.length&&nc>=0&&nc<sol_board[0].length){
                if(sol_board[nr][nc]==target.charAt(bef+1)&&visit[nr][nc]==false){
                    visit[nr][nc]=true;
                    if(hasWord(nr,nc,bef+1)) return true;
                    visit[nr][nc]=false;
                }
            }
        }
        return false;
    }
    
    public boolean exist(char[][] board, String word) { 
        visit= new boolean[board.length][board[0].length];
        sol_board = new char[board.length][board[0].length];
        target=word;
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                sol_board[i][j]=board[i][j];       
            }
        }
        
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j]==word.charAt(0)){
                    visit[i][j]=true;
                    if(hasWord(i,j,0)) return true;
                    visit[i][j]=false;
                }        
            }
        }
        return false;
    }
}