package bj_testproject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.ArrayList; 
import java.util.Collections;
import java.util.Iterator;

public class Main {
	
	public static boolean isSubPhonenumb(String s1, String s2) {
		if(s1.length()<s2.length()){
			if(s1.equals(s2.substring(0, s1.length()))){
				return true;
			}else {
				return false;
			}
		}
		return false;
	}
	
	public static void main(String args[]) {
		
		try {
			BufferedReader bf= new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(bf.readLine());
            
            boolean result = true;
            for(int i=0; i<t; i++){
                //for new test case
                int n =  Integer.parseInt(bf.readLine());
                ArrayList<String> set = new ArrayList<String>();
                result = true;
                for(int j=0; j<n; j++){
                	String phone_number = bf.readLine();
                	set.add(phone_number);
                }
                Collections.sort(set);
                Iterator<String> siter = set.iterator();
                String before = null;
                String now = null;
                while(siter.hasNext()) {
                	now = siter.next();
                	if(before!=null&&isSubPhonenumb(before,now)) {
                		result = false;
                		break;
                	}
                	before = now;
                }
                if(result) {
                	System.out.println("YES");
                }else {
                	System.out.println("NO");
                }
            }
            bf.close();
			
		}catch(IOException e) {
			System.exit(0);}
		
		
		
	}
	

}
