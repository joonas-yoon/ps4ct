import java.util.*;

class Solution {
     List<String> words;
     Set<String> words_set;
     int size;
    public  int[] memorized;
    public  String target;
    public  boolean wordBreak(String s, List<String> wordDict) {
        target=s;
        size=s.length();
        words = wordDict;
        words_set = new HashSet<String>();
        memorized = new int[s.length()]; //1 for true -1 for false

        Collections.sort(words);
        //System.out.println(words);

        boolean ans = dictHasString(0);
        System.out.println(ans);
        return ans;
    }
    public  boolean dictHasString(int st){ //0~st~target-1
        if(st>=size) return true;
        if(memorized[st]!=0){
            if(memorized[st]==1)return true;
            else return false;
        }

        for(int length=1;length<=20&&(st+length)<=size;length++){
            if(binarySearch(target.substring(st,st+length),0,words.size()-1)&&dictHasString(st+length)){
                memorized[st]=1;
                return true;
            }
        }
        memorized[st]=-1;
        return false;

    }

    public  boolean binarySearch(String s,int st,int ed){
        if(st==ed)return words.get(st).equals(s);
        if(st>ed) return false;

        int mid=(st+ed)/2;
        int res=words.get(mid).compareTo(s);
        if(res==0){
            return true;
        }else if(res>0){ //mid>s
            return binarySearch(s,st,mid-1);
        }else{ //mid<s
            return binarySearch(s,mid+1,ed);
        }
    }
}
