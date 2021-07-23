import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			
			int n = Integer.parseInt(bf.readLine());
			int maxValue = 1000000;
			long modTarget = 1000000009;
			long ans[][] = new long[maxValue+1][4];
			ans[1][1]=1;
			ans[1][0]=1;
			for(int i=2;i<=maxValue;i++) {
				ans[i][1] = (ans[i-1][1] + ans[i-1][2] + ans[i-1][3])%modTarget;
				ans[i][2] = ans[i-1][1];
				ans[i][3] = ans[i-1][2];
				ans[i][0] = (ans[i][1] + ans[i][2] + ans [i][3])%modTarget;
			}
			int target;
			for(int i=0;i<n;i++) {
				target=Integer.parseInt(bf.readLine());
				System.out.println(ans[target][0]);
			}
			
			
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
class 91 {
    
}
