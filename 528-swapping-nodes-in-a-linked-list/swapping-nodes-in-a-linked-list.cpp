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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr=head;
        ListNode *slow=head;
        ListNode *fast=head;
      
        for(int i=1;i<k;i++) {
            fast=fast->next;
            curr=curr->next;
        }
        if(fast==NULL){
           swap(fast->val,slow->val);
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;

        }
        swap(curr->val,slow->val);
        return head;

    }
};