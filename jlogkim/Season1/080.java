package jlog_kim;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.Iterator;
import java.util.PriorityQueue;

class Building {
	int st;
	int h;
	int ed;
	public Building(int st,int h,int ed) {
		this.st=st;
		this.h=h;
		this.ed=ed;
	}
	public String toString() {
		return st+" "+h+" "+ed;
	} 
}

public class Main {
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(bf.readLine());
			int arr[][] = new int[2*n][2];
			int idx=0;
			String splitted[];
			PriorityQueue<Building> q = new PriorityQueue<Building>(n, (e1, e2) -> Integer.compare(e2.h,e1.h));
			Comparator<Building> myComparator = new Comparator<Building>(){public int compare(Building e1,Building e2){
				if(e1.st==e2.st)return Integer.compare(e2.h, e1.h);
				else return Integer.compare(e1.st, e2.st);
			}};
			PriorityQueue<Building> inputq = new PriorityQueue<Building>(n, myComparator);
			for(int i=0;i<n;i++) {
				splitted = bf.readLine().split(" ");
				Building b = new Building(Integer.parseInt(splitted[0]),Integer.parseInt(splitted[1]),Integer.parseInt(splitted[2]));
				//Wq.add(b);
				inputq.add(b);
			}
			int preh=0;
			Building pre;
			int nowh;
			int preed=0;
			while(!inputq.isEmpty()) {
				preh=q.isEmpty()?0:q.peek().h;
				if(q.isEmpty()||q.peek().ed>=inputq.peek().st) {
					q.add(inputq.poll());
					if(preh<q.peek().h) {
						arr[idx][0]=q.peek().st;
						arr[idx][1]=q.peek().h;
						idx++;
					}
				}else {
					pre=q.poll();
					while(!q.isEmpty()&&q.peek().ed<=pre.ed)q.poll();
					nowh=q.isEmpty()?0:q.peek().h;
					if(pre.h>nowh) {
						arr[idx][0]=pre.ed;
						arr[idx][1]=nowh;
						idx++;
					}
				}
            }
            
			while(!q.isEmpty()) {
				pre=q.poll();
				while(!q.isEmpty()&&q.peek().ed<=pre.ed)q.poll();
				nowh=q.isEmpty()?0:q.peek().h;
				if(pre.h>nowh) {
					arr[idx][0]=pre.ed;
					arr[idx][1]=nowh;
					idx++;
				}
			}
			System.out.print(arr[0][0]+" "+arr[0][1]);
			for(int i=1;i<idx;i++) {
				System.out.print(" "+arr[i][0]+" "+arr[i][1]);
			}System.out.println();
			
		}catch(IOException e) {
			System.out.println("ioexception while reading input");
		}
		
	}

}