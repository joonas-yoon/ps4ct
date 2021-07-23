import java.util.Scanner;

public class Main {
	public final static int MAXINT=5000000;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		
		for(int t=0;t<tc;t++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int w = sc.nextInt();
			int map[][] = new int[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++)map[i][j]=MAXINT;
			}
			int st,ed,val;
			for(int i=0;i<m;i++) {
				st=sc.nextInt()-1;
				ed=sc.nextInt()-1;
				val=sc.nextInt();
				if(map[st][ed]>val) {
					map[st][ed]=val;
					map[ed][st]=val;
				}
			}
			for(int i=0;i<w;i++) {
				st=sc.nextInt()-1;
				ed=sc.nextInt()-1;
				val=(sc.nextInt())*-1;
				map[st][ed]=val;
			}
			int edgenumb=0;

			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++)if(map[i][j]<MAXINT)edgenumb++;
			}
			int way[][] = new int[edgenumb][2];
			edgenumb=0;
			//System.out.println("map");
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++)if(map[i][j]<MAXINT) {
					way[edgenumb][0]=i;
					way[edgenumb][1]=j;
					edgenumb++;
					//System.out.println(i+" "+j+" :"+map[i][j]);
				}
			}
			int shortest[] = new int [n];
			for(int i=1;i<n;i++)shortest[i]=MAXINT;
			
			for(int i=0;i<n-1;i++) {
				for(int e=0;e<edgenumb;e++) {
					if((shortest[way[e][0]]+map[way[e][0]][way[e][1]])<shortest[way[e][1]]) {
						shortest[way[e][1]]=shortest[way[e][0]]+map[way[e][0]][way[e][1]];
						//System.out.println(way[e][0]+" "+way[e][1]+"is used");
					}
				}
			}
			boolean negative_cycle=false;
			for(int e=0;e<edgenumb;e++) {
				if((shortest[way[e][0]]+map[way[e][0]][way[e][1]])<shortest[way[e][1]]) {
					//System.out.println(way[e][0]+" "+way[e][1]+"is used");
					negative_cycle=true;
					break;
				}
			}
			
			System.out.println(negative_cycle?"YES":"NO");
			
		}

	}
}
