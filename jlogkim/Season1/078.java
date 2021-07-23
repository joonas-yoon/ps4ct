class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        long dists[][] = new long[n][n];
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++)if(i!=j)dists[i][j]=Integer.MAX_VALUE;
        }
        
        for(int i=0;i<fares.length;i++) {
        	dists[fares[i][0]-1][fares[i][1]-1]=fares[i][2];
        	dists[fares[i][1]-1][fares[i][0]-1]=fares[i][2];
        }
        for(int i=0;i<n;i++) {
        	for(int st=0;st<n;st++) {
        		for(int ed=0;ed<n;ed++) {
        			dists[st][ed]=Math.min(dists[st][ed],dists[st][i]+dists[i][ed]);
        		}
        	}
        }
        
        long ans=dists[s-1][a-1]+dists[s-1][b-1];
        long tmp;
        for(int i=0;i<n;i++) {
        	tmp=dists[s-1][i]+dists[i][a-1]+dists[i][b-1];
        	if(tmp<ans)ans=tmp;
        }
        
        
        return (int)ans;
    }
}