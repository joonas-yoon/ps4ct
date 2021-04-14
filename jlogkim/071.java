import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;



class Solution {
    
    public String[] sortedorders;	
    public HashMap<String, Integer> map = new HashMap<String,Integer>();
	
    	public void makeSubSet(int order, String now, int idx, int target) {
		if(idx>=sortedorders[order].length())return;
		String newstr=now+sortedorders[order].charAt(idx);
		makeSubSet(order,now,idx+1,target);
		if(now.length()==(target-1)) {
			int count = map.containsKey(newstr)?map.get(newstr):0;
			map.put(newstr,count+1);
			return;
		} 
		makeSubSet(order,newstr,idx+1,target);
		return;
	}
    
    public String[] solution(String[] orders, int[] course) {
  	sortedorders=new String[orders.length];
    	
    	boolean alpha[] =new boolean[26]; 
    	for(int i=0;i<orders.length;i++) {
    		String newstr="";
    		for(int j=0;j<26;j++)alpha[j]=false;
    		for(int j=0;j<orders[i].length();j++) {
    			alpha[orders[i].charAt(j)-'A']=true;
    		}
    		for(int j=0;j<26;j++)if(alpha[j])newstr+=(char)('A'+j);
    		sortedorders[i]=newstr;
    	}
    	for(int i=0;i<orders.length;i++) {
    		System.out.println(orders[i]);
    	}
    	
    	ArrayList<String> unsorted_answer = new ArrayList<String>();
    	int max=0;
    	int value;
    	for(int i=0;i<course.length;i++) {
    		map.clear();
    		max=0;
    		for(int j=0;j<sortedorders.length;j++) {
    			makeSubSet(j,"",0,course[i]);
    		}
    		
    		for(String key: map.keySet()) {
    			value=map.get(key);
    			if(value>max)max=value;
    		}
    		if(max>=2) {
	    		for(String key: map.keySet()) {
	    			if(map.get(key)==max) {
	    				unsorted_answer.add(key);
	    			}
	    		}
    		}
    	}
    	Collections.sort(unsorted_answer);
    	String[] answer = new String[unsorted_answer.size()];
    	for(int i=0; i<unsorted_answer.size();i++) {
    		answer[i]=unsorted_answer.get(i);
    	}
        return answer;
    }
}