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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *dNode=new ListNode(0,list1);
        ListNode *apre=dNode;
        ListNode *curr=list1;
         ListNode *temp=list2;
        for(int i=0;i<a;i++){
            apre=apre->next;
            curr=curr->next;
        }
        ListNode *front=NULL;
        for(int i=0;i<(b-a +1);i++){
           front=curr->next;
            curr=front;
        }
      while(temp!=NULL && temp->next!=NULL){
        apre->next=temp;
        apre=temp;
        temp=temp->next;
     
      }
      temp->next=curr;

       return dNode->next;
        
    }
};

            
       