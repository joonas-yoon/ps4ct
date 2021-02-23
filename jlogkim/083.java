import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.SortedSet;
import java.util.TreeSet;

class Pair {
	int x; 
	int y;
	public Pair(int x,int y) {this.x=x; this.y=y;}
	public void set(int x,int y) {this.x=x; this.y=y;}
}

public class Main {
	static Map<Integer,Pair> map;
	public static void putMap(int st, int ed, int bus, boolean cut) {
		if(!map.containsKey(st)) map.put(st, new Pair(ed,bus));
		else {
			if(!cut&&ed>map.get(st).x) map.get(st).set(ed, bus);
			if(cut&&ed>=map.get(st).x) map.get(st).set(ed, bus);
		}
	}
	public static void main(String args[]) {
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(bf.readLine());
			int m = Integer.parseInt(bf.readLine());
			map = new HashMap<Integer,Pair>();
			
			String splitted[];
			int a,b;
			
			for(int i=0;i<m;i++) {
				splitted=bf.readLine().split(" ");
				a = Integer.parseInt(splitted[0]);
				b = Integer.parseInt(splitted[1]);
				if(a>b) {
					putMap(0,b,-1,true); //cut된애가 0-가장 max를 차지하여, 포함되지 않는 경우로 들어가는 가능성을 배제
					putMap(a,b+n,i+1,false);
				}else {
					putMap(a,b,i+1,false);
				}
			}
			SortedSet<Integer> keys = new TreeSet<>(map.keySet());
			LinkedList<Integer> answer = new LinkedList<Integer>();
			int max=0;
			Pair p;
			for(Integer key : keys) {
				p = map.get(key);
				if(p.x>max) {
					answer.add(p.y);
					max=p.x;
				}
			}
			Collections.sort(answer);
			Iterator<Integer> iter = answer.iterator();
			int ans=iter.next();
			if(ans!=-1) {System.out.print(ans);}
			else {
				System.out.print(iter.next());
			}
			while(iter.hasNext()) {
				System.out.print(" "+iter.next());
			}
		}catch(IOException e) {
			System.out.println("Exeption: IO Exception");
		} 
	}

}
