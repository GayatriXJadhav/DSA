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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode *dNode=new ListNode(0,head);
       ListNode *leftpre=dNode;
       ListNode *curr=head;
       for(int i=0;i<left-1;i++){
        leftpre=leftpre->next;
        curr=curr->next;
       }
       ListNode *startMergeNode=curr;
       ListNode *prev=NULL;
         ListNode *front=NULL;
       for(int i=0;i<(right-left + 1);i++){
        front=curr->next;
         curr->next=prev;
         prev=curr;
         curr=front;
       }
       leftpre->next=prev;
       startMergeNode->next=curr;
       return dNode->next;
    }
};