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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         ListNode *dNode=new ListNode(-1,head);
         ListNode *p=dNode;
         ListNode *temp=head;
        set<int>st;
        for(int i=0;i<nums.size();i++){
           st.insert(nums[i]);
        }
        while(temp!=NULL ){
            if(st.find(temp->val)!=st.end()){
                

                p->next=temp->next;
                temp=temp->next;
                
               
                
            }
            else
            {
                p=temp;
                temp=temp->next;
            }
        }
        return dNode->next;
    }
};