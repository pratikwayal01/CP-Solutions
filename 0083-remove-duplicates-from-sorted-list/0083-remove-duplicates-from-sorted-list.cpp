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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head){
            return head;
        }
        unordered_set<int> seen;
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            if (seen.find(current->val) != seen.end()) {
                prev->next = current->next;
                delete current;
            } else {
                seen.insert(current->val);
                prev = current;
            }
            current = prev->next;
        }
        return head;
    }
};