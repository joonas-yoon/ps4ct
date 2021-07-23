class Solution {
    public int[] getIntArr(String s){
    int sharpcount=0;
    for(int i=0;i<s.length();i++) {
        if(s.charAt(i)=='#')sharpcount++;
    }
    int intarr[]=new int[s.length()-sharpcount];
    int idx=0;
    for(int i=0;i<s.length();i++) {
        if(s.charAt(i)=='#') {
            intarr[idx-1]+=7;
        }else {
            intarr[idx++]=s.charAt(i)-'A';
        }
    }
    /*for(int i=0;i<intarr.length;i++) {
        System.out.print(intarr[i]+" ");
    }System.out.println();*/
    return intarr;
}

public int isInside(String melody,String song,int length) {
    
    int[] melodyarr=getIntArr(melody);
    int[] songarr=getIntArr(song);
    
    //한바퀴를 돌았으면 한바퀴의 길이가 적립이 되어야함. 
    //남아있는 길이가 감당을 못하면 return
    int sdx=0;
    for(int i=0;i<songarr.length;i++) {
        if((length-i)<melodyarr.length) break;
        sdx=i;
        for(int mdx=0; mdx<melodyarr.length; mdx++) {
            if(melodyarr[mdx]!=songarr[sdx])break;
            if(mdx==(melodyarr.length-1))return length;
            sdx=(++sdx)%songarr.length;
        }
    }		
    
    return -1;
}

public String solution(String m, String[] musicinfos) {
    String answer = "(None)";
    String songsplitted[];
    String splitted1[],splitted2[];
    int btw;
    
    int prevalue=-1;
    int returnvalue=-1;
    for(int i=0;i<musicinfos.length;i++) {
        songsplitted = musicinfos[i].split(",");
        splitted1=songsplitted[0].split(":");
        splitted2=songsplitted[1].split(":");
        btw = (Integer.parseInt(splitted2[0])-Integer.parseInt(splitted1[0]))*60+(Integer.parseInt(splitted2[1])-Integer.parseInt(splitted1[1]));
        returnvalue=isInside(m,songsplitted[3],btw);
        if(returnvalue!=-1&&returnvalue>prevalue) {
            prevalue=returnvalue;
            answer=songsplitted[2];
        }
    }
    
    return answer;
}
}