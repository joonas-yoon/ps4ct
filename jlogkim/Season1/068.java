import java.util.Scanner;

public class Main {
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n,m,r;
		n=sc.nextInt(); m=sc.nextInt(); r=sc.nextInt();
		int items[]=new int[n];
		for(int i=0;i<n;i++) {items[i]=sc.nextInt();}
		
		int path[][]= new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				path[i][j]=30;
			}
		}
		int st,ed,len;
		for(int i=0;i<r;i++) {
			st=sc.nextInt()-1;
			ed=sc.nextInt()-1;
			len=sc.nextInt();
			path[st][ed]=len;
			path[ed][st]=len;
        }
        //Floyd Warshall Algorithm 
		for(int i=0;i<n;i++) {
			for(int s=0;s<n;s++) {
				for(int t=s+1;t<n;t++) {
					if(s!=t) {
					if(path[s][t]>(path[s][i]+path[i][t])) {
						path[s][t]=path[s][i]+path[i][t];
						path[t][s]=path[s][t];
						}
					}
				}
			}
		}
		int max=0;
		int it=0;
		for(int s=0;s<n;s++) {
			it=items[s];
			for(int t=0;t<n;t++) {
				if(path[s][t]<=m)it+=items[t];
			}
			if(it>max)max=it;
		}

		System.out.println(max);
	}
}
