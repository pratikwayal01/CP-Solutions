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
    int length(ListNode *head){
        int len=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        int count=0;
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* ptr = head;
        
        while (count < (len - n - 1)) {
            count++;
            ptr = ptr->next;
        }
        
        ListNode* temp = ptr->next;
        ptr->next = ptr->next->next; 
        
        delete temp; 
        return head; 
    }
};