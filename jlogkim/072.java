import java.lang.StringBuilder;
class Solution {
    public String solution(String p) {
    	if(p=="")return "";
    	StringBuilder sb = new StringBuilder();
    	
    	String answer="";
    	int net = 0;
    	int i=0;
    	for(i=0;i<p.length();i++) {
    		if(p.charAt(i)=='(')net-=1;
    		else net+=1;
    		if(net==0)break;
    	}
    	int n=0;
    	String v = "";
    	if(i<(p.length()-1))
    	 v = solution(p.substring(i+1));
    	for(int st=0;st<=i;st++) {
    		if(p.charAt(st)=='(')n++;
    		else {
    			if(n<=0) {
    				sb.append("(");
    				sb.append(v);
    				sb.append(")");
    				for(int idx=1;idx<i;idx++) {
    					if(p.charAt(idx)=='(') {sb.append(')');}
    					else { sb.append('(');}
    				}
    				break;
    			}
    		}
    	}
    	if(sb.length()==0) {
    		sb.append(p.substring(0, i+1));
    		sb.append(v);
    	}
    	answer = sb.toString();
        return answer;
    }
}