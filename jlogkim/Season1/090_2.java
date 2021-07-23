import java.util.Arrays;

class Solution {
    
    public long getTime(String firstpart){
        String mysplitted[]=firstpart.split(":");
        long time=(Integer.parseInt(mysplitted[0])*3600000+Integer.parseInt(mysplitted[1])*60000+
                   (long)(Double.parseDouble(mysplitted[2])*1000));
        return time;
    }
    
    public long getTime(String firstpart, String secondpart){
        long first=getTime(firstpart);
        int second = (int)(Double.parseDouble(secondpart.substring(0, secondpart.length()-1))*1000);
        return first-second;
    }

    public int solution(String[] lines) {
        int answer = 0;
        String splitted[];
        
        Long st_arr[] = new Long[lines.length];
        Long ed_arr[] = new Long[lines.length];

        for(int i=0;i<lines.length;i++){
            splitted=lines[i].split(" ");
            st_arr[i]=getTime(splitted[1],splitted[2])+1;
            ed_arr[i]=getTime(splitted[1]);
        }
        Arrays.sort(st_arr);
        long tg_st;
        long tg_ed;

        int numb = 0;
        
        int max = 0;
        
        int add_index = 0;
        int delete_index = 0;
        
        for(int i=0;i<lines.length;i++) {
        	tg_st=ed_arr[i];
        	tg_ed=ed_arr[i]+999;      	
            while(add_index<lines.length&&st_arr[add_index]<=tg_ed) {
            	numb++;
            	add_index++;
            }
            while(delete_index<lines.length&&ed_arr[delete_index]<tg_st) {
            	numb--;
            	delete_index++;
            }
           
        	if(numb>max)max=numb;
        }
        
        return max;
    }
}