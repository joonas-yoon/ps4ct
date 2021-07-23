package bj_testproject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.io.IOException;

class Node{
	int r;
	int c;
	public Node(int r, int c) {
		this.r=r;
		this.c=c;
	}
}

public class Main {
	
	public static int[][] way = {{1,0},{0,1},{-1,0},{0,-1}};
	public static int CHECKED = 2;
	public static int INMAP = 1;
	public static int COLOR = 0;
	public static int TRUE = 1;
	public static int FALSE = 0;
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
            /*
             * 
             * INPUT EXAMPLE
			6 3
			0000000000
			0000000300
			0054000300
			1054502230
			2211122220
			1111111223
			*/
		
			String[] splitted = bf.readLine().split(" ");
			int n = Integer.parseInt(splitted[0]);
			int k = Integer.parseInt(splitted[1]);
			
			int map[][][] = new int[n][10][3]; 
			//INDEX 0 FOR COLOR 1 FOR IF IN MAP OR NOT AND 2 FOR IF CHECKED BEFORE
			
			Stack<Node> stack = new Stack<Node>(); 
			//FOR BFS
			Stack<Node> storage = new Stack<Node>(); 
			//FOR CHECK K NUMBER FOUND OR NOT IF FOUND USE STORAGE TO AFFECT MAP
			
			//GET THE INPUT
			for(int r=0;r<n;r++) {
				String line = bf.readLine();
				for(int c=0;c<10;c++) {
					map[r][c][COLOR] = line.charAt(c)-'0';
					map[r][c][INMAP] = map[r][c][0] != 0 ? TRUE:FALSE;
					map[r][c][CHECKED] = FALSE;
				}
			}
			
			boolean done = false;
			int imtr;
			int imtc;
			
			while(!done) {//DONE BECOME TRUE WHEN ALL POSSIBLE K GROUP FOUNDED 
				done=true;
				//initialize
				for(int cp=0;cp<10;cp++) {
					for(int rp=0; rp<n&&map[n-1-rp][cp][COLOR]!=0; rp++) {
						map[n-1-rp][cp][INMAP] = TRUE;
						map[n-1-rp][cp][CHECKED] = FALSE;
					}
				}
				//find same color larger than k 
				//bcs it is more efficient to find group from the bottom, use another pointer  
				for(int cp=0;cp<10;cp++) {
					for(int rp=0; rp<n&&map[n-1-rp][cp][INMAP]==TRUE; rp++) {
						if(map[n-1-rp][cp][CHECKED] == FALSE){
							//find block having same color more than k by using bfs or dfs
							Node startnode = new Node(n-1-rp,cp);
							stack.push(startnode);
							storage.push(startnode);
							map[n-1-rp][cp][CHECKED]=TRUE;
							while(!stack.isEmpty()) {
								Node mid = stack.pop();
								for(int i=0;i<4;i++) {
									imtr = mid.r+way[i][0];
									imtc = mid.c+way[i][1];
									if(imtr>=0&&imtr<n&&imtc>=0&&imtc<10) {
										if(map[imtr][imtc][INMAP]==TRUE&&map[imtr][imtc][CHECKED]==FALSE&&map[imtr][imtc][COLOR]==map[mid.r][mid.c][COLOR]) {
											Node newNode = new Node(imtr, imtc);
											stack.push(newNode);
											storage.push(newNode);
											map[imtr][imtc][CHECKED]=TRUE;
										}
									}
								}
							}
							if(storage.size()>=k) {
								done=false;
								while(!storage.isEmpty()) {
									Node imtNode = storage.pop();
									map[imtNode.r][imtNode.c][COLOR]=0;
								}
							}else {
								storage.clear();
							}
						}
					}
				}
				//printmap(map,n);
				//zero compact
				for(int cp=0;cp<10;cp++) {
					int nr=0;
					for(int rp=0; rp<n&&map[n-1-rp][cp][INMAP]==TRUE; rp++) {
						if(map[n-1-rp][cp][COLOR]>0) {
							map[n-1-nr++][cp][COLOR]=map[n-1-rp][cp][COLOR];
						}
					}
					for(;nr<n&&map[n-1-nr][cp][INMAP]==TRUE;nr++) {
						map[n-1-nr][cp][COLOR]=0;
					}
				}
				//printmap(map,n);
			}
			
			printmap(map,n);
            bf.close();
			
		}catch(IOException e) {
			System.exit(0);}
		
		
		
	}
	public static void printmap(int[][][] map,int n) {
		for(int r=0;r<n;r++) {
			for(int c=0;c<10;c++) {
				System.out.print(map[r][c][COLOR]);
			}
			System.out.println();
		}
		
	}
	

}
