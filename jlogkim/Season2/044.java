/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    public void reorderList(ListNode head) {
         //find final node 
        //and divide the original one with final node make pre finalnode's next pointer null
        ListNode pre=null;
        ListNode node=head;
        
        while(node.next!=null){
            pre=node;
            node=node.next;
        }
        
        if(pre!=null&&pre!=head){
            pre.next=null;
            ListNode next_head=head.next;
            reorderList(next_head);
            node.next=head.next;
            head.next=node;
        }
    }
}