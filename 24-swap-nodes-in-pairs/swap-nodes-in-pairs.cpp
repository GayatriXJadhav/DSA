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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
       ListNode *dNode=new ListNode(-1);
       ListNode *prev=dNode;
       dNode->next=head;
       ListNode* first=head;
      
       while(first!=NULL && first->next!=NULL){
        ListNode* second=first->next;
        prev->next=second;
        first->next=second->next;
        second->next=first;
      
        prev=first;
        first=prev->next;
        
       } 
       return dNode->next;
    }
};