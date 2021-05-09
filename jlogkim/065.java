import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.PriorityQueue;
class Pair {
    int r,c;
    public Pair(int r, int c){this.r=r; this.c=c;}
}
class DisjointSet implements Comparable<DisjointSet>{
    int r,c,nr,nc,difference;
    public DisjointSet(int r,int c,int nr,int nc,int difference){
        this.r=r;
        this.c=c;
        this.nr=nr;
        this.nc=nc;
        this.difference=difference;
    }
    @Override
    public int compareTo(DisjointSet o) {
        return this.difference > o.difference ? 1 : - 1;
    }
}

class Solution {
    int bundle_set[][];
    int set[];
    private int get_set(int r, int c){
        int s=bundle_set[r][c];
        while(s!=set[s]){
            s=set[s];
        }
        return s;
    }

    private int way[][] = {{1,0},{0,1},{-1,0},{0,-1}};
    public int solution(int[][] land, int height) {
        int answer = 0;
        int size = land.length;
        bundle_set = new int[size][size];
        Stack<Pair> dfs= new Stack<Pair>();
        PriorityQueue<DisjointSet> disjoint = new PriorityQueue<>();
        int set_numb=1;
        Pair p;
        int nr;
        int nc;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(bundle_set[i][j]==0){
                    //FIND ADJACENT SET OF BUNDLE
                    dfs.add(new Pair(i,j));
                    bundle_set[i][j]=set_numb;
                    //DFS
                    while(!dfs.isEmpty()){
                        p=dfs.pop();
                        for(int w=0;w<4;w++){
                            nr=p.r+way[w][0];
                            nc=p.c+way[w][1];
                            if(nr>=0&&nr<size&&nc>=0&&nc<size){
                                if(bundle_set[nr][nc]==0&&((land[p.r][p.c]-land[nr][nc])>=-height)&&((land[p.r][p.c]-land[nr][nc])<=height)){
                                    dfs.add(new Pair(nr,nc));
                                    bundle_set[nr][nc]=set_numb;
                                }
                            }
                        }
                    }
                    set_numb++;
                }
            }
        }
        set = new int[set_numb];
        for(int i=1;i<set_numb;i++){
            set[i]=i;
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for(int w=0;w<2;w++){
                    nr=i+way[w][0];
                    nc=j+way[w][1];
                    if(nr>=0&&nr<size&&nc>=0&&nc<size&&bundle_set[i][j]!=bundle_set[nr][nc]){
                        disjoint.add(new DisjointSet(i,j,nr,nc,Math.abs(land[i][j]-land[nr][nc])));
                    }
                }
            }
        }


        //FIND DISJOINT SET AND COMBINE IN MINIUMUM HEIGHT
        DisjointSet dset;
        while(!disjoint.isEmpty()) {
            dset=disjoint.poll();
            if(get_set(dset.r,dset.c)!=get_set(dset.nr,dset.nc)){
                answer+=dset.difference;
                set[get_set(dset.r,dset.c)]=get_set(dset.nr,dset.nc);
            }
        }


        return answer;
    }
}