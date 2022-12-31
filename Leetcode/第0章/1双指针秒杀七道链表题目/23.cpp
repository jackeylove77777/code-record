/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<queue>
#include<vector>
#include<iostream>
struct cmp{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        ListNode* dummy = new ListNode(-1);//虚拟头节点
        ListNode* p = dummy;
        int k = lists.size();
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto node : lists){
            if(node!=nullptr){
                pq.push(node);
            }
        }
        while(pq.size()){
            ListNode* head = pq.top();
            pq.pop();
            p->next = head;
            p = p->next;
            if(head->next!=0){
                pq.push(head->next);
            }
        }
        return dummy->next;

    }
};