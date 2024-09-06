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
   void insertAtHead(ListNode* &head, int val) {
        ListNode* new_node = new ListNode(val);
        new_node->next = head;
        head = new_node; 
    }
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) return nullptr;
        stack<int> stk;
        ListNode* temp = head;
        while (temp != nullptr) {
            stk.push(temp->val);
            temp = temp->next;
        }
        int max_val = stk.top();
        stk.pop();
        ListNode* new_head = new ListNode(max_val);
        while (!stk.empty()) {
            if (stk.top() >= max_val) {
                max_val = stk.top();
                insertAtHead(new_head, max_val);  
            }
            stk.pop();
        }
        return new_head;
    }
};