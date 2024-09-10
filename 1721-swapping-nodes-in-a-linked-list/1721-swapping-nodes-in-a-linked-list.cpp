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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
            second = (k-- > 1) ? second : second->next;
        }
        swap(first->val, second->val);
        return head;
    }
};