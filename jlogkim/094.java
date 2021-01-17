import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {

	public static void main(String args[]) {

		try {
			BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
			
			int t = Integer.parseInt(bf.readLine());
			
			String[] splitted ;
			int n, m;
			int a, b;
			int count;
			
			for(int testcase=0;testcase<t;testcase++) {
				splitted = bf.readLine().split(" ");
				count = 0;
				n = Integer.parseInt(splitted[0]);
				m = Integer.parseInt(splitted[1]);
				
				int connected[]=new int[n+1];
				
				for(int i=1; i<=n; i++) {
					connected[i]=i;
				}
				
				for(int i=0; i<m; i++) {
					splitted = bf.readLine().split(" ");
					a = Integer.parseInt(splitted[0]);
					b = Integer.parseInt(splitted[1]);
					if(connected[a]!=connected[b]) {
						int target=connected[b];
						for(int j=1;j<=n;j++) {
							if(connected[j]==target) {
								connected[j]=connected[a];
							}
						}
						count++;
					}
				}
				System.out.println(count);
			}
			
		}catch(IOException e) {
			System.exit(0);}
		
		
		
	}
	

}
