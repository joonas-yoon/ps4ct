import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Iterator;


public class Main {
	static int bag[];
	static int c;
	static int n;
	
	static List<Integer> list1;
	static List<Integer> list2;
	//from 0 to n/2-1
	public static void firstSearch(int point,int sum) {
		if(sum>c)return;
		if(point==(n/2)) {
			list1.add(sum);
			return;}
		firstSearch(point+1,sum);
		firstSearch(point+1,sum+bag[point]);
	}
	public static void secondSearch(int point,int sum) {
		if(sum>c)return;
		if(point==n) {
			list2.add(sum);
			return;}
		secondSearch(point+1,sum);
		secondSearch(point+1,sum+bag[point]);
	}
	
	
	
	public static void main(String args[]) {
		try {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String splitted[] = bf.readLine().split(" ");
		
		n = Integer.parseInt(splitted[0]);
		c = Integer.parseInt(splitted[1]);
		list1=new ArrayList<>();
		list2=new ArrayList<>();
		
		splitted = bf.readLine().split(" ");
		
		bag=new int[n];
		for(int i=0;i<n;i++) {
			bag[i]=Integer.parseInt(splitted[i]);
		}
		firstSearch(0,0);
		secondSearch(n/2,0);
		
		Collections.sort(list1);
		Collections.sort(list2);

		Iterator<Integer> iter =list1.iterator();
		long ans=0;
		int target;
		int index=list2.size()-1;
		
		while(iter.hasNext()) {
			target=iter.next();
			while((index>=0)&&((target+list2.get(index))>c)) {
				index--;
			}
			if(index<0)return;
			else {ans+=(index+1);}
		}
		System.out.println(ans);
		
		}catch(IOException e) {
			System.out.println("IOException occurs");
		}
	}
}
