/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==0){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(1){
            if(fast->next!=0&&fast->next->next!=0){
                fast = fast->next->next;
            }else{
                return false;
            }
            slow=slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};