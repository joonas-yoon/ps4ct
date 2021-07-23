public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { 
        this.val = val; 
        left=null;
        right=null;}
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution {
  TreeNode root = null;
  int mnums[];
  public TreeNode getSubTreeRoot(int st,int ed){
      int length=ed-st+1;
      int mid = st+length/2;
      TreeNode l=null;
      TreeNode r=null;
      if(mid>st){l=getSubTreeRoot(st,mid-1);}
      if(ed>mid){r=getSubTreeRoot(mid+1,ed);}
      TreeNode node=new TreeNode(mnums[mid],l,r);
      return node;
  }
  
  
  public TreeNode sortedArrayToBST(int[] nums) {
      mnums = new int[nums.length];
      for(int i=0; i<nums.length; i++){
          mnums[i]=nums[i];
      }
      TreeNode ans=getSubTreeRoot(0,nums.length-1);
      return ans;
  }
}