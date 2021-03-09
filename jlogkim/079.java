import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

class Node{
	String s;
	int count;
	public Node(String s,int count) {
		this.s=s;
		this.count=count;
	}
	public void connect(int count) {
		this.count+=count;
	}
	public String toString() {
		return s+" "+count;
	}
}

public class Main {
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String target = bf.readLine();
			HashMap<String,Node> map= new HashMap<String,Node>();
			Node t = new Node(target,1);
			map.put(target, t);
			Queue<Node> q = new LinkedList<Node>();
			q.add(t);
			int ql;
			String s1;
			String s2;
			Node node;
			boolean flag;
			for(int i=target.length()-1;i>=1;i--) {
				ql=q.size();
				for(int j=0;j<ql;j++) {
					node=q.poll();
					s1=node.s.substring(1);
					s2=node.s.substring(0, node.s.length()-1);
					flag=false;
					if(s1.equals(s2)) {
						flag=true;
					}
					if(map.containsKey(s1)) {
						map.get(s1).connect(node.count);
					}else {
						Node newnode = new Node(s1,node.count);
						q.add(newnode);
						map.put(s1, newnode);
					}
					if(!flag) {
						if(map.containsKey(s2)) {
							map.get(s2).connect(node.count);
						}else {
							Node newnode = new Node(s2,node.count);
							q.add(newnode);
							map.put(s2, newnode);
						}
					}
					
				}
			}
			
			int ans=0;
			while(!q.isEmpty())ans+=q.poll().count;
			System.out.println(ans);
		}catch(IOException e) {
			System.out.println("ioexception while reading input");
		}
		
	}

}
