/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }
         ListNode *slow=head;
          ListNode *fast=head->next;
          while(fast != slow){
          if(fast==nullptr || fast->next==nullptr){
            return false;
          } 
          slow=slow->next;
          fast=fast->next->next; 
          }
          return head;
    }
};