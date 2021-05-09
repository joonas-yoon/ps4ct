class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        
        boolean existance[] = new boolean [26];
        int prefix[] = new int[26];
        
        for(int i=0; i <26; i++){
            prefix[i]=-1;
        }
        
        int pre=skill.charAt(0)-'A';

        int now;
        for(int i=1; i <skill.length(); i++){
            now=skill.charAt(i)-'A';
            prefix[now]=pre;
            pre=now;
        }
        String target;
        boolean flag=true;
        for(int tc=0; tc<skill_trees.length; tc++){
            flag=true;
            for(int i=0;i<26;i++){
                existance[i]=false;
            }
            target = skill_trees[tc];
            for(int i=0;i<target.length();i++){
                if(prefix[target.charAt(i)-'A']>=0&&existance[prefix[target.charAt(i)-'A']]==false){flag=false;
                        break;                                                                           }
                existance[target.charAt(i)-'A']=true;
            }
            if(flag)answer++;                
        }        
        
        return answer;
    }
}