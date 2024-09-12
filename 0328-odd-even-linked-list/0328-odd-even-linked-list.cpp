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
    ListNode* oddEvenList(ListNode* head) {
         if (head == nullptr || head->next == nullptr){
            return head;
         }
        ListNode* prev=head;
        ListNode* cur=head->next;
        ListNode* temp=cur;
        while(cur != nullptr && cur->next != nullptr){
            prev->next=prev->next->next;
            cur->next=cur->next->next;
            prev=prev->next;
            cur=cur->next;
        }
        prev->next=temp;
        return head;
    }
};