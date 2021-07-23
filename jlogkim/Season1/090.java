import java.util.List;
import java.util.ArrayList; 

class Sector {
	
    public long starttime;
    public long endtime;
    public Sector(long starttime, long endtime) {
    	this.starttime=starttime;
    	this.endtime=endtime;
    }
}

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
        Sector sectorlist[]=new Sector[lines.length];

        for(int i=0;i<lines.length;i++){
            splitted=lines[i].split(" ");
            sectorlist[i]=new Sector(getTime(splitted[1],splitted[2])+1,(getTime(splitted[1])));
        }
        long tg_st;
        long tg_ed;
        
        int ind;
        int numb;
        int max=0;
        for(int i=0;i<lines.length;i++) {
        	numb = 0;
        	tg_st=sectorlist[i].endtime;
        	tg_ed=sectorlist[i].endtime+999;
        	for(int j = i; j>=0; j--) {
        		if(sectorlist[j].endtime>=tg_st) numb++;
        		else break;
        	}
        	for(int j = i+1; j<lines.length; j++) {
        		if(sectorlist[j].starttime<=tg_ed) numb++;
        	}
        	if(numb>max)max=numb;
        }
        
        return max;
    }
}