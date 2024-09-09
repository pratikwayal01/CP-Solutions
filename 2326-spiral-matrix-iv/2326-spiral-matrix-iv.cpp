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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        ListNode* temp = head;
        int top=0,bottom=m-1;
        int left=0,right=n-1;
        while(temp!=nullptr && top <= bottom && left <= right){
             for (int c = left; c <= right && temp != nullptr; c++) {
                int val = -1;
                if (temp != nullptr) {
                    val = temp->val;
                    temp = temp->next;
                }
                ans[top][c] = val;
            }
            top++;
            for (int r = top; r <= bottom && temp != nullptr; r++) {
                int val = -1;
                if (temp != nullptr) {
                    val = temp->val;
                    temp = temp->next;
                }
                ans[r][right] = val;
            }
            right--;
            for (int c = right; c >= left && temp != nullptr; c--) {
                int val = -1;
                if (temp != nullptr) {
                    val = temp->val;
                    temp = temp->next;
                }
                ans[bottom][c] = val;
            }
            bottom--;

 
            for (int r = bottom; r >= top && temp != nullptr; r--) {
                int val = -1;
                if (temp != nullptr) {
                    val = temp->val;
                    temp = temp->next;
                }
                ans[r][left] = val;
            }
            left++;
        }

        return ans;
    }
};