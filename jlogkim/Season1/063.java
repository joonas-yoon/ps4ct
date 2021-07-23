class Solution {
    public String target;
    public int size;
    public int ways[];
    public int numDecodings(String s) {
        target=s;
        size=s.length();
        ways = new int[size];

        if(isEncoded(size-1,size-1))ways[size-1]=1;

        if(size>=2){
            if(isEncoded(size-2,size-1))ways[size-2]=1;
            if(isEncoded(size-2,size-2))ways[size-2]+=ways[size-1];
        }

        for(int st=size-3;st>=0;st--){
            if(isEncoded(st,st))ways[st]+=ways[st+1];
            if(isEncoded(st,st+1))ways[st]+=ways[st+2];
        }
        return ways[0];
    }
    public boolean isEncoded(int st,int ed){
        if(st==ed)return target.charAt(st)!='0';
        if(target.charAt(st)=='1'){
            return true;
        }if(target.charAt(st)=='2'){
            return target.charAt(ed)<='6';
        }
        return false;
    }
}