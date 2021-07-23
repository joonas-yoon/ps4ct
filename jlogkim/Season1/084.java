import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Iterator;


class Request implements Comparable<Request>{
	int from;
	int to;
	int baggage;
	public Request(int from, int to, int baggage) {
		this.from=from;
		this.to=to;
		this.baggage=baggage;
	}
	@Override
	public int compareTo(Request o) {
		if(this.from<o.from) {
			return -1;
		}else if(this.from==o.from) {
			if(this.to<o.to)return -1;
			else return 1;
		}else {
			return 1;
		}
	}
}

public class Main {
	
	public static int n,c,m;
	public static int truck[];
	public static int answer;
	public static int truckHas; 
	
	public static boolean putBaggage(int to,int weight) {
		int left=weight;
		int target=Math.min(weight, c-truckHas);
		truck[to]+=target;
		left-=target;
		truckHas+=target;
		boolean flag=left==0?true:false;
		for(int i=n-1;i>to&&left>0;i--) {
			if(truck[i]>0) {
				flag=true;
				target=Math.min(truck[i], left);
				left-=target;
				truck[i]-=target;
				truck[to]+=target;
			}
		}
		return flag;
	}
	
	public static void main(String args[]) {
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String splitted[] = bf.readLine().split(" ");
			
			n = Integer.parseInt(splitted[0]);
			c = Integer.parseInt(splitted[1]);
			m = Integer.parseInt(bf.readLine());
			truck = new int[n];
			
			List<Request> llist[] = new ArrayList[n];
			for(int i=0;i<n;i++)llist[i]=new ArrayList<Request>();
			int imtfrom;
			int imtto;
			int imtbaggage;
			for(int i=0;i<m;i++) {
				splitted = bf.readLine().split(" ");
				imtfrom = Integer.parseInt(splitted[0])-1;
				imtto = Integer.parseInt(splitted[1])-1;
				imtbaggage = Integer.parseInt(splitted[2]);
				llist[imtfrom].add(new Request(imtfrom,imtto,imtbaggage));
			}
			for(int i=0;i<n;i++) {
				Collections.sort(llist[i]);
			}
			Iterator<Request> iter;
			Request req;
			answer = 0;
			truckHas = 0;
			
			for(int i=0;i<n;i++) {
				answer+=truck[i];
				truckHas-=truck[i];
				truck[i]=0;
				iter=llist[i].iterator();
				//System.out.println(truckHas);

				while(iter.hasNext()){
					req=iter.next();
					//System.out.println("put "+req.from+" "+req.to+" "+req.baggage);
					if(!putBaggage(req.to,req.baggage)) break;
				}
				//for(int j=0;j<n;j++)System.out.print(truck[j]);
				//System.out.println();
			}
			System.out.println(answer);
			
		}catch(IOException e) {
			System.out.println("Exeption: IO Exception");
		} 
	}

}
