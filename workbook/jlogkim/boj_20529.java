import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	/*
	 * http://blog.naver.com/PostView.nhn?blogId=jinhan814&logNo=222192861453&categoryNo=11&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
	 * 해당 풀이에서, 비둘기집 원리, 그리고 처음에 input을 처리하는 방식을 참고하면 좋을듯 
	 * */
	public static int mbti_pool[]=new int[16];
	public static int mbti_length[][] =new int[16][16];
	public static int combi[]=new int[3];
	
	public static int getMinCombi(int count, int pointer) {
		int min=Integer.MAX_VALUE;
		
		if(count==3) {
			return mbti_length[combi[0]][combi[1]]+mbti_length[combi[0]][combi[2]]+mbti_length[combi[1]][combi[2]];
		}else if(pointer>=16) {
			return Integer.MAX_VALUE;
		}
		if(mbti_pool[pointer]==0) return getMinCombi(count,pointer+1);
		else {
			combi[count]=pointer;
			min=getMinCombi(count+1,pointer+1);
			min=Math.min(min, getMinCombi(count,pointer+1));
			if(count<=1&&mbti_pool[pointer]==2){
				combi[count]=pointer;
				combi[count+1]=pointer;
				min=Math.min(min,getMinCombi(count+2,pointer+1));
			}
			
		}
		
		return min;
	}
	
	
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(bf.readLine());
			int n;
			int now;
			
			int xor_result;
			int diff_result;
			for(int i=0; i<16; i++) {
				for(int j=i; j<16; j++) {
					diff_result=0;
					xor_result = i^j;
					while(xor_result>0) {
						if((xor_result&1)>0)diff_result++;
						xor_result=xor_result>>1;
					}
					mbti_length[i][j]=mbti_length[j][i]=diff_result;
				}
			}
			
			boolean flag=false;
			int ans;
			for(int tc=0; tc<t; tc++) {
				flag=false;
				for(int j=0;j<16;j++){mbti_pool[j]=0;}
				
				n = Integer.parseInt(bf.readLine());
				String splitted[]= bf.readLine().split(" ");
				
				for(int j=0;j<splitted.length;j++) {
					now=0;
					if(splitted[j].charAt(0)=='E') now+=8;
					if(splitted[j].charAt(1)=='S') now+=4;
					if(splitted[j].charAt(2)=='T') now+=2;
					if(splitted[j].charAt(3)=='J') now+=1;
					mbti_pool[now]++;
					if(mbti_pool[now]==3) {
						flag=true;
						break;
					}
				}
				
				if(flag)ans=0;
				else {
					ans=getMinCombi(0,0);
				}
				System.out.println(ans);
			}
			
			
	
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
