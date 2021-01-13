import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;

public class Main {
	
	static Stack<Integer> waybackduck;
	public static void main(String args[]) {
		
		waybackduck=new Stack<Integer>();
		try {
			BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
		
			//int duckhouse[]=new int[1048577];

			String[] splitted = bf.readLine().split(" ");
			int n = Integer.parseInt(splitted[0]);
			int q = Integer.parseInt(splitted[1]);
			
			boolean duckhouse[]=new boolean[n+1];
			
			int duckwant;
			int pointer;
			for(int duck=1; duck<=q; duck++) {
				duckwant = Integer.parseInt(bf.readLine());
				pointer = duckwant;
				while(pointer>0) {
					if(duckhouse[pointer]==true) {
						waybackduck.push(pointer);
					}
					pointer/=2;
				}
				if(waybackduck.isEmpty()) {
					System.out.println("0");
					duckhouse[duckwant]=true;
				}else {
					System.out.println(waybackduck.pop());
					waybackduck.clear();
				}
						
			}
				
			
		}catch(IOException e) {
			System.exit(0);}
		
		
		
	}
	

}
