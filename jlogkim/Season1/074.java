import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;



public class Main {
	
	static int tri[][]=new int[6][3];
	static boolean used[]= new boolean[6];
	static int usednumb=0;
	
	public static int minTri(int st,int ed) {
		int sol=-1;
		int subsol=-1;
		
		if(usednumb==5) {
			for(int i=0;i<6;i++) {
				if(used[i]==false) {
					for(int j=0;j<3;j++) {
						if(tri[i][j]==st&&tri[i][(j+1)%3]==ed) {
							return tri[i][(j+2)%3]; //간소화 가능
						}
					}
				}
			}
		}

		for(int i=0;i<6;i++) {
			if(used[i]==false) {
				for(int j=0;j<3;j++) {
					if(tri[i][j]==st) {
						usednumb++;
						used[i]=true;
						subsol=minTri(tri[i][(j+1)%3],ed);
						if(subsol!=-1) {
						sol=Math.max(sol, tri[i][(j+2)%3]+subsol);}
						usednumb--;
						used[i]=false;
					}
				}
			}
		}
		return sol;
		
	}
	public static void main(String args[]) {
		try {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String splitted[];
		String tc="*";
		
		while(tc.equals("*")) {
			for(int i=0;i<6;i++) {
				used[i]=false;
				splitted=bf.readLine().split(" ");
				tri[i][0]=Integer.parseInt(splitted[0]);
				tri[i][1]=Integer.parseInt(splitted[1]);
				tri[i][2]=Integer.parseInt(splitted[2]);
			}
			
			int sol = -1;
			used[0]=true;
			usednumb=1;
			int subsol;
			for(int j=0;j<3;j++) {
				subsol=minTri(tri[0][(j+1)%3],tri[0][j]);
				if(subsol!=-1)
				sol=Math.max(sol,tri[0][(j+2)%3]+subsol);
			}
			if(sol!=-1) {
				System.out.println(sol);
			}else {
				System.out.println("none");
			}
			tc=bf.readLine().strip();
		}
		
		}catch(IOException e) {
			System.out.println("IOException occurs");
		}
	}
}
