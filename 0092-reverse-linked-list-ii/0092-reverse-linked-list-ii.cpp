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
        
        // Use a dummy head to easily handle cases where 'left' is the head node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        // 1. Move 'prev' to the node right before position 'left'
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // 'curr' will mark the initial node at 'left' position
        ListNode* curr = prev->next;
        
        // 2. Perform local reversal right - left times
        for (int i = 0; i < right - left; ++i) {
            ListNode* nxt = curr->next;
            
            // Adjust the links to move 'nxt' behind 'prev'
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory
        return newHead;
    }
};