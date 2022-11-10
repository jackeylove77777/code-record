/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MiddleNode(ListNode head) {
        if(head is null)return null;
        (var slow,var fast)=(head,head);
        while(fast!=null&&fast.next!=null){
            if(fast!= null){
                fast=fast.next;
            }
            if(fast!= null){
                fast=fast.next;
            }
            slow=slow.next;
        }
        return slow;
    }
}