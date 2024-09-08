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
    int length(ListNode* head ){
        if(head == NULL) return 0;
        int len=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k,nullptr);
        int len=length(head);
        int size = len/k;
        int extra = len % k;
        ListNode* ptr=head;
       for(int i=0;i<k;i++){
        ans[i]=ptr;
        int curr_length=size+(i<extra?1:0);

        for(int j=1;j<curr_length;j++){
         if(ptr!=nullptr){
            ptr=ptr->next;
         }
        }
          if(ptr!=nullptr){
            ListNode * next=ptr->next;
            ptr->next=NULL;
            ptr=next;
          }
        }
        return ans;
    }
};