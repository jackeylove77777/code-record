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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==0)return nullptr;
        ListNode* a=head,*b=head;
        for(int i=0;i<k;i++)a=a->next;
        while(a!=nullptr){
            a=a->next;
            b=b->next;
        }
        return b;
    }
};