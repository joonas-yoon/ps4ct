import java.io.IOException;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

class Node implements Comparable<Node> {
	int length;
	int value;
	ArrayList<Integer> bus = new ArrayList<>();
    int distance;
	
	@Override 
	public int compareTo(Node obj) {
		if(this.length<obj.length)return -1;
		else if(this.length==obj.length&&this.distance<obj.distance)return -1;
		else return 1;
	}
	public Node(int value, int length){
		this.value=value;
		this.length=length;
	}
	public void impactTo(int to){
        this.distance=Math.abs(value-to);
	}
	
	@Override
	public String toString(){
		return (this.value)+": "+this.length;
	}
}

public class Main {
	

	final static int MAX=1000000000;	
	
	static PriorityQueue<Node> pq = new PriorityQueue<>();

	
	public static void main(String[] args) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            String splitted[];
            int bus_array[][] = new int[1000][1000];
            int n = Integer.parseInt(bf.readLine());
            int m = Integer.parseInt(bf.readLine());
            Node node_array[]= new Node[n];
            
            for(int i=0;i<n;i++) {
            	node_array[i]= new Node(i, MAX);
            }
            for(int i=0;i<1000;i++) {
            	for(int j=0;j<1000;j++) {
            		bus_array[i][j]=-1;
            	}
            }
            
            
            int from,to,length;
            for(int i=0;i<m;i++) {
            	splitted=bf.readLine().split(" ");
            	from=Integer.parseInt(splitted[0])-1;
            	to=Integer.parseInt(splitted[1])-1;
            	length=Integer.parseInt(splitted[2]);
            	if(bus_array[from][to]==-1) {
            		node_array[from].bus.add(to);
            		bus_array[from][to]=length;
        		}else if(bus_array[from][to]>length) {
            		bus_array[from][to]=length;
        		}
            }
            
            splitted=bf.readLine().split(" ");
        	from=Integer.parseInt(splitted[0])-1;
        	to=Integer.parseInt(splitted[1])-1;
        	
        	if(from==to) {
        		System.out.println(0);
        		return;
        	}
        	
            for(int i=0;i<n;i++) {
            	if(i==from)node_array[i].length=0;
            	node_array[i].impactTo(to);
            	pq.add(node_array[i]);
            }
        	
        	Node imt;
        	while(!pq.isEmpty()) {
        		imt=pq.poll();
        		//System.out.println(imt);
        		if(imt.value==to) {
        			System.out.println(imt.length);
        			break;
        		}
        		for(int i: imt.bus) {
        			if((imt.length+bus_array[imt.value][i])<
        					node_array[i].length) {
        				node_array[i].length=(imt.length+bus_array[imt.value][i]);
        				pq.remove(node_array[i]);
        				pq.add(node_array[i]);
        				//System.out.println("update "+i+":"+node_array[i].length);
        			}
        		}
        	}
        	
            
        }catch(IOException e){

        }
    }
}