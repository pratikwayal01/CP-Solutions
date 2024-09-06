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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>S(nums.begin(),nums.end());
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* newHead=temp;
        while(temp->next != nullptr){
            if(S.count(temp->next->val)){
                ListNode* dummy =temp->next;
                temp->next=temp->next->next;
                delete(dummy);
            }
            else{
                temp=temp->next;
            }
        }
        return newHead->next;

    }
};