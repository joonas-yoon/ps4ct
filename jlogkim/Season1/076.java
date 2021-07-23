class Solution {
    public boolean checkSymmetric(TreeNode a, TreeNode b){
        //assume we should check nullness of node a and node b
        if(a==null&&b==null)return true;
        else if(a==null||b==null) return false;
        
        if(a.val!=b.val){return false;}
        if(checkSymmetric(a.left,b.right)&&checkSymmetric(a.right,b.left))
            return true;
        else 
            return false;
        
    }
    
    
    public boolean isSymmetric(TreeNode root) {
        return checkSymmetric(root.left,root.right);
    }
}