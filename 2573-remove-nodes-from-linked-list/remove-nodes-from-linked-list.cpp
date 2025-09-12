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
    ListNode* reverseLL(ListNode* head) {
        if (!head && !head->next)
            return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* reverseHead = reverseLL(head);
        ListNode* curr = reverseHead;
        ListNode* prev = new ListNode(-1, curr);
        int m = -1;
        while (curr) {
            while (curr && curr->val < m)
                curr = curr->next;
            if (curr) {
                prev->next = curr;
                prev = curr;
                m = prev->val;
                curr = curr->next;
            }
            else{
                prev->next=curr;
            }
        }
        return reverseLL(reverseHead);
    }
};