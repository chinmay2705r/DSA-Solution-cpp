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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int pos = 1; 

        int firstIndex = -1;
        int prevIndex = -1;
        int minDistance = INT_MAX;

        while (curr->next != nullptr) {
            ListNode* nxt = curr->next;

            if ((curr->val > prev->val && curr->val > nxt->val) ||
                (curr->val < prev->val && curr->val < nxt->val)) {
                
                if (firstIndex == -1) {
                    firstIndex = pos;
                } else {
                    minDistance = min(minDistance, pos - prevIndex);
                }
                prevIndex = pos;
            }

            prev = curr;
            curr = nxt;
            pos++;
        }
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        return {minDistance, prevIndex - firstIndex};
    }
};