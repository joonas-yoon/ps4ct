import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.Stack;

public class Main {
	static int way[][] = {{1,0},{-1,0},{0,1},{0,-1}};
	public static void main(String args[]) {
		try {
			
		Stack<Integer> st = new Stack<Integer>();	
			
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String splitted[];
		String input;
		int r,c;
		splitted=bf.readLine().split(" ");
		r = Integer.parseInt(splitted[0]);
		c = Integer.parseInt(splitted[1]);
		char map[][]=new char[r][c];
		
		for(int i=0;i<r;i++) {
			input=bf.readLine();
			for(int j=0;j<c;j++) {
				map[i][j]=input.charAt(j);
				if(map[i][j]=='S')st.push(i*500+j);
			}
		}
		int x,y;
		boolean possible=true;
		int tx,ty;
		while(!st.isEmpty()&&possible) {
			x=st.pop();
			y=x%500;
			x/=500;
			for(int i=0;i<4;i++) {
				tx=x+way[i][0];
				ty=y+way[i][1];
				if(tx>=0&&tx<r&&ty>=0&&ty<c) {
					if(map[tx][ty]=='.')map[tx][ty]='D';
					else if(map[tx][ty]=='W')possible=false;
				}
			}
		}
		if(possible) {
			System.out.println(1);
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					System.out.print(map[i][j]);
				}System.out.println();
			}
		}else {
			System.out.println(0);
		}
		
		}catch(IOException e) {
			System.out.println("IOException occurs");
		}
	}
}
