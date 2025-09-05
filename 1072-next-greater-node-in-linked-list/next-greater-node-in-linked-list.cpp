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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;
        ListNode *temp=head;
        while(temp!=NULL){
            res.push_back(temp->val);
            temp=temp->next;
        }
        stack<int>st;
      
        for(int i=res.size()-1;i>=0;i--){

            while(!st.empty() && st.top()<=res[i]) st.pop();
            int temp=(st.empty()) ? 0:st.top();
            st.push(res[i]);
            res[i]=temp;
        }
        return res;
    }
};