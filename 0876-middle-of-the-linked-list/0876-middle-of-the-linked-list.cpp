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
    int length(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int mid=length(head)/2;
        ListNode* ptr=head;
        int count=0;
        while(count<mid){
            count++;
            ptr=ptr->next;
        }
        return ptr;
    }
};