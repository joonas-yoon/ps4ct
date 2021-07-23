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

class Node implements Comparable<Node> {
    int numb;
    int list_numb;
    public Node(int numb,int list_numb){
        this.numb=numb;
        this.list_numb=list_numb;
    }
    @Override
    public int compareTo(Node target) {
        return this.numb <= target.numb ? -1 : 1;
    }
}

class Solution {
    ListNode head=null;
    ListNode tail=null;
    public void putNode(ListNode node){
        node.next=null;
        if(head==null){
            head=node;
            tail=node;
        }else{
            tail.next=node;
            tail=node;
        }
    }
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Node> queue= new PriorityQueue<Node>();
        for(int i=0;i<lists.length;i++){
            if(lists[i]!=null){
                queue.offer(new Node(lists[i].val, i));
            }
        }
        ListNode targetnode;
        while(!queue.isEmpty()){
            Node n = queue.poll();
            targetnode=lists[n.list_numb];
            lists[n.list_numb]=lists[n.list_numb].next;
            if(lists[n.list_numb]!=null){
                n.numb=lists[n.list_numb].val;
                queue.offer(n);  
            }
            putNode(targetnode);
        }
        return head;
    }
}