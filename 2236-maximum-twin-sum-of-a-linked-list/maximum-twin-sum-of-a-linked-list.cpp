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
    ListNode *reverse(ListNode *head){
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL){
            ListNode *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHead=reverse(slow->next);
        ListNode *t1=head;
         ListNode* t2=secondHead;
         int maxSum=0, sum=0;
         while(t1 && t2){
            sum=t1->val + t2->val;
            maxSum=max(maxSum,sum);
            t1=t1->next;
            t2=t2->next;
         }
         reverse(secondHead);
         return maxSum;


    }
};