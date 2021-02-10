import java.io.BufferedReader;

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Pair{
	int r;
	int c;
	public Pair(int r, int c) {
		this.r=r;
		this.c=c;
	}
}

public class Main {

	
	public static int ways[][]= {{1,0},{0,1},{-1,0},{0,-1}};
	public static int map[][];
	public static int ICE=1;
	public static int WATER=0;
	public static int SWAN1=2;
	public static int SWAN2=3;
	public static int r;
	public static int c;
	
	public static Queue<Pair> bfsqueue = new LinkedList<Pair>();
	
	public static Queue<Pair> q1 = new LinkedList<Pair>();
	public static Queue<Pair> q2 = new LinkedList<Pair>();
	
	public static void printmap() {
		  for(int i=0;i<r;i++) {
			  for(int j=0;j<c;j++) {
				  if(map[i][j]==ICE) {
					  System.out.print("X");
				  }else if(map[i][j]==WATER){
					  System.out.print(".");
				  }else {
				  System.out.print(map[i][j]);
				  }
			  }
			  System.out.println();
		  }
	}
	public static boolean bfs(int swan, Queue<Pair> base) {
		while(!base.isEmpty()) {
			bfsqueue.add(base.poll());
		}
		int imtr;
		int imtc;
		Pair p;
		boolean nearIce=false;
		
		while(!bfsqueue.isEmpty()) {
			p=bfsqueue.poll();
			nearIce=false;
			for(int k=0;k<4;k++) {
				imtr=p.r+ways[k][0];
				imtc=p.c+ways[k][1];
				if(imtr>=0&&imtr<r&&imtc>=0&&imtc<c) {
					if(map[imtr][imtc]!=swan) {
						if(map[imtr][imtc]==WATER) {
							map[imtr][imtc]=swan;
							bfsqueue.add(new Pair(imtr,imtc));
						}else if(map[imtr][imtc]==ICE){
							nearIce=true;
						}else {
							return true;
						}
					}
				}
			}
			if(nearIce) {
				base.add(new Pair(p.r,p.c));
			}
		}
	
		return false;
	}
	
	public static void main(String args[]) {

		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String splitted[] = bf.readLine().split(" ");
			r = Integer.parseInt(splitted[0]);
			c = Integer.parseInt(splitted[1]);
			map = new int[r][c];
			boolean first=true;
			int day=0;

			Queue<Pair> willmelt = new LinkedList<Pair>();
			
			String row;
			int imtr;
			int imtc;
			
			for(int i=0;i<r;i++) {
				row = bf.readLine();
				for(int j=0;j<c;j++) {
					switch(row.charAt(j)) {
					case 'X':
						map[i][j]=ICE;
						break;
					case '.':
						map[i][j]=WATER;
						break;
					case 'L':
						if(first) {
							map[i][j]=SWAN1;
							first=false;
							q1.add(new Pair(i,j));
						}else {
							map[i][j]=SWAN2;
							q2.add(new Pair(i,j));
						}
						break;
					}
				}
			}
			
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					if(map[i][j]==ICE) {
						for(int k=0;k<4;k++) {
							imtr=i+ways[k][0];
							imtc=j+ways[k][1];
							if(imtr>=0&&imtr<r&&imtc>=0&&imtc<c) {
								if(map[imtr][imtc]!=ICE) { //여기서 water 동등조건으로 비교했다가 66% 정도에서 에러가 남
									willmelt.add(new Pair(i,j));
									break;
								}
							}
						}
					}
				}
			}
			
			int leftices=0;
			Pair p;
			while(true) {
				
				if(bfs(SWAN1,q1)) {
					break;
				}
				if(bfs(SWAN2,q2)) {
					break;
				}

				day++;
				//ice meling;
				leftices=willmelt.size();
				//System.out.println(leftices);
				for(int i=0;i<leftices;i++)
				{
					p=willmelt.poll();
					if(map[p.r][p.c]==ICE) {
						map[p.r][p.c]=WATER;
						
						for(int k=0;k<4;k++) {
							imtr=p.r+ways[k][0];
							imtc=p.c+ways[k][1];
							if(imtr>=0&&imtr<r&&imtc>=0&&imtc<c) {
								if(map[imtr][imtc]==ICE) {
									willmelt.add(new Pair(imtr,imtc));
								}
							}
						}
						
					}
				}
				
			  if(willmelt.size()==0)break;
			}
			
			System.out.println(day);

		}catch (IOException e) {
			System.out.println("catch io exception "+e.toString());
		}
		
		
	}

}
