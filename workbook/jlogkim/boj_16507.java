import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String splitted[] = bf.readLine().split(" ");
			int numb;
			int r = Integer.parseInt(splitted[0]);
			int c = Integer.parseInt(splitted[1]);
			int q = Integer.parseInt(splitted[2]);
			int sumMap[][] = new int[r+1][c+1];
			int rowSum[][] = new int[r+1][c+1];
			
			for(int i=1; i<=r; i++) {
				splitted = bf.readLine().split(" ");
				for(int j=1; j<=c; j++) {
					numb = Integer.parseInt(splitted[j-1]);
					rowSum[i][j]=rowSum[i][j-1]+numb;
					sumMap[i][j]=sumMap[i-1][j]+rowSum[i][j];
				}
			}
			
			int r1,c1,r2,c2;
			int targetSum=0;
			for(int i=0; i<q; i++) {
				splitted = bf.readLine().split(" ");
				r1 = Integer.parseInt(splitted[0])-1;
				c1 = Integer.parseInt(splitted[1])-1;
				r2 = Integer.parseInt(splitted[2]);
				c2 = Integer.parseInt(splitted[3]);
				targetSum=sumMap[r2][c2]-sumMap[r2][c1]-sumMap[r1][c2]+sumMap[r1][c1];
				System.out.println((int)(targetSum/((r2-r1)*(c2-c1))));
			}
	
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
