import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.lang.Math;

public class Main {

	public static void main(String args[]) {
		
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String splitted[] = bf.readLine().split(" ");
			int N = Integer.parseInt(splitted[0]);
			int r = Integer.parseInt(splitted[1]);
			int c = Integer.parseInt(splitted[2]);
			
		    int nown = N;
		    int point = 0;
		    int count = 0 ;
		    
		    int smallr = r;
		    int smallc = c;
		   
		    while(nown > 0) {
		    	point = 0;
		    	int box = (int)Math.pow(2, nown-1);
		    	if(smallr>=box) {
		    		point+=2;
		    		smallr -= box;
		    	}
		    	if(smallc>=box) {
		    		point+=1;
		    		smallc -= box;
		    	}
		    	count += box*box*point;
		    	nown--;
		    }
		    System.out.println(count);
			
			
		}catch (IOException e) {
			System.out.println("catch io exception ");
		}
		
		
	}

}
