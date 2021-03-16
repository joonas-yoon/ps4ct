class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        int m = key.length;
        int n = lock.length;
        
        int st[][]= {{0,0},{m-1,0},{m-1,m-1},{0,m-1}};
        int rway[][] = {{1,0},{0,1},{-1,0},{0,-1}};
        int cway[][] = {{0,1},{-1,0},{0,-1},{1,0}};
        
        int r,c;
        int cr,cc;
        boolean check=true;
        for(int br=(-m+1);br<=(n-1);br++) {
        	for(int bc=(-m+1);bc<=(n-1);bc++) {
   			 for(int t=0;t<4;t++) {
   				check=true;
        		for(int lr=0;lr<n;lr++) {
        			for(int lc=0;lc<n;lc++) {
        				 if(lr>=br&&lr<=(br+(m-1))&&lc>=bc&&lc<=(bc+(m-1))) {
        					 r=lr-br;
        					 c=lc-bc;
        					 cr=st[t][0]+r*rway[t][0]+c*cway[t][0];
        					 cc=st[t][1]+r*rway[t][1]+c*cway[t][1];
        					 if((key[cr][cc]+lock[lr][lc])!=1)check=false;
        				 }else {
        					 if(lock[lr][lc]==0)check=false;
        				 }
        				 if(!check)break;
        				}
        			if(!check)break;
        			}
        			if(check)return true;
        		}
        	}
        }
        return false;

    }
}