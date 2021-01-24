import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.io.IOException;
import java.util.LinkedList;
import java.util.Iterator;

public class Main {

	static int peoples[] ;
	static LinkedList<Integer> connection[];
	static long maxValue[][];
	static boolean visited[];

	static long max(long a,long b) {
		return a>b?a:b;
	}
	
	static long getMaxValue(int now, int isSelected) {
		
		visited[now] = true;
		if(maxValue[now][isSelected]!=-1) return maxValue[now][isSelected];
		
		Iterator<Integer> iter = connection[now].iterator();
		int pointer;
		if(isSelected == 1) {
			maxValue[now][isSelected]=peoples[now];
			while(iter.hasNext()) {
				pointer = iter.next();
				if(visited[pointer]==false) {
					maxValue[now][isSelected]+=getMaxValue(pointer,0);
				}
			}
		}else {
			maxValue[now][isSelected]=0;
			while(iter.hasNext()) {
				pointer = iter.next();
				if(visited[pointer]==false) {
					maxValue[now][isSelected]+=max(getMaxValue(pointer,1),getMaxValue(pointer,0));
				}
			}
		}		
		
		visited[now] = false;
		return maxValue[now][isSelected];
	}
	
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			
			int n = Integer.parseInt(bf.readLine());
			peoples = new int[n+1];
			visited = new boolean[n+1];
			maxValue = new long[n+1][2];
			String splitted[] = bf.readLine().split(" ");
			
			connection = new LinkedList[n+1];
			for(int i=1; i<=n; i++) {
				peoples[i]=Integer.parseInt(splitted[i-1]);
				connection[i]=new LinkedList<Integer>();
				maxValue[i][0]=-1;
				maxValue[i][1]=-1;
			}
			
			int a;
			int b;
			
			for(int i=0;i<n-1;i++) {
				splitted = bf.readLine().split(" ");
				a = Integer.parseInt(splitted[0]);
				b = Integer.parseInt(splitted[1]);
				connection[a].add(b);
				connection[b].add(a);
			}

			System.out.println(max(getMaxValue(1,0), getMaxValue(1,1)));
	
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
