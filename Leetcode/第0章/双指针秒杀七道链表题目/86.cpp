class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode();
        ListNode* dummy2 = new ListNode();
        ListNode* p1=dummy1,*p2=dummy2,*temp=nullptr;
        while(head!=nullptr){
            if(head->val<x){
                p1->next=head;
                p1=p1->next;
            }else{
                p2->next=head;
                p2=p2->next;
            }
            temp=head;
            head=head->next;
            temp->next=nullptr;
        }
        p1->next=dummy2->next;
        return dummy1->next;
    }
};