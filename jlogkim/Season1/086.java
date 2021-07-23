class Solution {
    int map[][]=new int[25*26+26][2];
    
    public char getUpper(char target){
        if(target>='a'&&target<='z'){
            return Character.toUpperCase(target);
        }else if(target>='A'&&target<='Z'){
            return target;
        }else{
            return '0';
        }
    }
    public void makeMap(String str, int group){
        char first;
        char second;
        for(int i=0;i<str.length()-1;i++){
            first=getUpper(str.charAt(i));
            second=getUpper(str.charAt(i+1));
            if(first!='0'&&second!='0'){
                map[(first-'A')*26+(second-'A')][group]++;
            }
        }
    }
    
    public int solution(String str1, String str2) {
    	int answer;
        makeMap(str1,0);
        makeMap(str2,1);
        int summax=0;
        int summin=0;
        for(int i=0;i<map.length;i++){
            summax+=Math.max(map[i][0],map[i][1]);
            summin+=Math.min(map[i][0],map[i][1]);
        }
        if(summax==0){ return 65536;}
        else {
        	answer=65536*summin/summax;
        }
        return answer;
    }
}