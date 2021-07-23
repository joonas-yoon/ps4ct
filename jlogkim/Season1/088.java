import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

class Edge implements Comparable<Edge>{
	public int x;
	public int y;
	public Double length;
	public Edge(int x, int y, double length) {
		this.x=x;
		this.y=y;
		this.length=length;
	}
	public void print() {
		System.out.println(x+" "+y+" : "+length);
	}
	@Override
	public int compareTo(Edge o) {
		if(length<o.length)return -1;
		else return 1;
	}
}


public class Main {
	
	static int map[][];
	
	public static double getDistance(int a, int b) {
		return Math.sqrt(Math.pow(map[a][0]-map[b][0],2)+Math.pow(map[a][1]-map[b][1],2));
	}
	public static void combine(int a, int b) {
		for(int i=0;i<map.length;i++) {
			if(map[i][2]==b) {
				map[i][2]=a;
			}
		}
	}
	
	public static void main(String args[]) {
		
		double answer = 0;
		
		try {
			List<Edge> sorted_edge = new ArrayList<Edge>();
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String splitted[] = bf.readLine().split(" ");
			int n = Integer.parseInt(splitted[0]);
			int m = Integer.parseInt(splitted[1]);
			map = new int[n][3];
			
			for(int i=0;i<n;i++) {
				splitted = bf.readLine().split(" ");
				map[i][0] = Integer.parseInt(splitted[0]);
				map[i][1] = Integer.parseInt(splitted[1]);
				map[i][2] = i;
				for(int j=i-1;j>=0;j--) {
					sorted_edge.add(new Edge( j, i, getDistance(i, j)));
				}
			}
			
			Collections.sort(sorted_edge);
			
			int a;
			int b;
			for(int i=0; i<m; i++) {
				splitted = bf.readLine().split(" ");
				a = Integer.parseInt(splitted[0])-1;
				b = Integer.parseInt(splitted[1])-1;
				combine(map[a][2], map[b][2]);
			}
			
			Iterator<Edge> iter = sorted_edge.iterator();
			
			iter = sorted_edge.iterator();
			Edge target;
			while(iter.hasNext()) {
				target=iter.next();
				if(map[target.x][2]!=map[target.y][2]) {
					answer+=target.length;
					combine(map[target.x][2],map[target.y][2]);
				}
			}
			
			System.out.printf("%.2f\n",answer);
	
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
