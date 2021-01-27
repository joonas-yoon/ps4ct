import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    
	public static int FOUND = 1;
	public static int NOTFOUND = 0;
	
	public static int planets[][];
	public static int m;
	public static int n;
	
	public static boolean isSame(int a, int b) {
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				if(planets[a][i]==planets[a][j]) {
					if(planets[b][i]!=planets[b][j]) {
						return false;
					}
				}else if(planets[a][i]>planets[a][j]) {
					if(planets[b][i]<=planets[b][j]) {
						return false;
					}
				}else {
					if(planets[b][i]>=planets[b][j]) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String splitted[] = bf.readLine().split(" ");
			m = Integer.parseInt(splitted[0]);
			n = Integer.parseInt(splitted[1]);
			int ans=0;
			planets = new int[m][n];
			
			for(int i=0;i<m;i++) {
				splitted = bf.readLine().split(" ");
				for(int j=0;j<n;j++) {
					planets[i][j]=Integer.parseInt(splitted[j]);
				}
			}
			
			for(int i=0;i<m-1;i++) {
				for(int j=i+1;j<m;j++) {
					ans+=isSame(i,j)==true?1:0;
				}
			}
			
			System.out.println(ans);
			
			
			
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
