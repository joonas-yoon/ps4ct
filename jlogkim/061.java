import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


/*
6 4
0100
1110
1000
0000
0111
0000
* */
class Node{
    int r,c;
    boolean used;
    int length;
    public Node(int r,int c, boolean used, int length){
        this.r=r; this.c=c; this.used=used; this.length=length;
    }
}
public class Main {
    final static int NOT_USED=0;
    final static int USED=1;
    public static int way[][] = {{1,0},{-1,0},{0,1},{0,-1}};
    public static void main(String args[]) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            String splitted[];
            String line;
            splitted = bf.readLine().split(" ");
            int n = Integer.parseInt(splitted[0]);
            int m = Integer.parseInt(splitted[1]);

            boolean map[][] = new boolean[n][m];
            int min[][][] = new int [n][m][2];

            for(int r=0;r<n;r++){
                line=bf.readLine();
                for(int c=0;c<m;c++){
                    map[r][c]=line.charAt(c)=='0'?true:false; //true -> road, false -> wall
                }
            }
            for(int r=0;r<n;r++){
                for(int c=0;c<m;c++){
                    min[r][c][NOT_USED]=n*m;
                    min[r][c][USED]=n*m;
                }
            }
            //bfs start if 0 is is not visited,
            Queue<Node> q = new LinkedList<>();

            //bfs
            min[0][0][NOT_USED]=1;
            q.add(new Node(0,0,false,1));

            Node node;
            int nr,nc;
            while(!q.isEmpty()){
                node=q.poll();
                for(int i=0;i<4;i++){
                    nr=node.r+way[i][0];
                    nc=node.c+way[i][1];
                    if(nr>=0&&nr<n&&nc>=0&&nc<m){
                        if(map[nr][nc]){ //road
                            if(!node.used){ //not use crack the wall yet.
                                if(min[nr][nc][NOT_USED]>(node.length+1)){
                                    min[nr][nc][NOT_USED]=node.length+1;
                                    q.add(new Node(nr,nc,node.used,node.length+1));
                                }
                            }else{//used crack the wall
                                //if not used로 들린적이 없거나, not used 보다 값이 작을때 +
                                //used로 들린적이 없거나 used 보다 값이 작을 때
                                if(min[nr][nc][NOT_USED]>(node.length+1)&&min[nr][nc][USED]>(node.length+1)){
                                    min[nr][nc][USED]=node.length+1;
                                    q.add(new Node(nr,nc,node.used,node.length+1));
                                }
                            }
                        }else if(!node.used){ //wall and not use crack the wall yet.
                            if(min[nr][nc][USED]>(node.length+1)){
                                min[nr][nc][USED]=node.length+1;
                                q.add(new Node(nr,nc, true,node.length+1));
                            }
                        }
                    }
                }
            }
            int ans=Math.min(min[n-1][m-1][USED],min[n-1][m-1][NOT_USED]);
            if(ans!=n*m||n*m==1){
            System.out.println(ans);}
            else System.out.println(-1);
        }catch(IOException e){
            System.out.println(e.toString());
        }
    }
}
