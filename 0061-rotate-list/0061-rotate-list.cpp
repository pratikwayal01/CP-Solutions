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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next|| k==0) return head;
        int len =1;
         ListNode* temp = head;
         while(temp->next){
          len++;
          temp=temp->next;
        }

        if(k % len == 0) return head;
        k = k%len;
        int count = len -k;
         temp->next=head;
        ListNode*  lastnode = head;
        while(--count) lastnode = lastnode->next;
        ListNode* newhead = lastnode->next;
        lastnode->next = NULL;
        return newhead;
    }
};