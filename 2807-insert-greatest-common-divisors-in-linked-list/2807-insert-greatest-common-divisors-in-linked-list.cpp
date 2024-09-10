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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev=head;
        ListNode* cur=head->next;
        while(cur!=nullptr){
            int g = gcd(prev->val,cur->val);
            ListNode * temp = new ListNode(g);
            prev->next=temp;
            temp->next=cur;
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};