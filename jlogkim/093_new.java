package bj_testproject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;

class pair{
	public int x, y;
	public pair(int x,int y) {
		this.x=x;
		this.y=y;
	}
}


class Node{
	
	int itself;
	public LinkedList<pair> child;
	
	public long large1, large2;

	public Node(int itself){
		this.itself = itself;
		child = new LinkedList<pair>();
		large1 = 0L;
		large2 = 0L;
	}
	public void put(long l) {
		if(l>large1) {
			large2 = large1;
			large1 = l;
		}else if(l>large2) {
			large2 = l;
		}
	}
	public void print(int n) {
		pair p;
		System.out.print(n+"'s child");
		Iterator<pair> it = child.iterator();
		while(it.hasNext()) {
			p = it.next();
			System.out.print(p.x+": "+p.y+" ");
		}System.out.println();
	}
	
}

public class Main {
	
	static long ans;
	public static Node graph[];
	static pair pointer;
	
	static long getMaxLength(int n) {
		Node target = graph[n];
		Iterator<pair> iter = target.child.iterator();
		
		pair p;
		long imt=0;
		while(iter.hasNext()) {
			p=iter.next();
			imt = getMaxLength(p.x);
			target.put(imt+p.y);
		}
		if((target.large1+target.large2)>ans) {
			ans = target.large1+target.large2;
		}
		return target.large1;
	}
	

	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(bf.readLine());

			graph = new Node[n+1];
			for(int i=1; i<=n; i++) {
				graph[i]=new Node(i);
			}
			
			String splitted[];
			int parent;
			int ch;
			int l;
			ans = 0;
			
			for(int i=0;i<n-1;i++) {
				splitted = bf.readLine().split(" ");
				parent = Integer.parseInt(splitted[0]);
				ch = Integer.parseInt(splitted[1]);
				l = Integer.parseInt(splitted[2]);
				graph[parent].child.add(new pair(ch,l));
			}
			getMaxLength(1);
			
			System.out.println(ans);
			
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
