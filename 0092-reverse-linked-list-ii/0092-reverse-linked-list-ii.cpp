/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
    
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right - left; ++i) {
            ListNode* nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};