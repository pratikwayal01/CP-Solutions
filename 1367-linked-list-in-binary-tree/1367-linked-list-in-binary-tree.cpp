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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode* head, TreeNode* root, bool started){
        if(head == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        bool flag = false;
        if(!started){
            flag = flag || solve(head, root->left, started) || solve(head, root->right, started);
        }
        if(flag){
            return flag;
        }
        if(head->val == root->val){
            flag = flag || solve(head->next, root->left, true) || solve(head->next, root->right, true);
        }
        return flag;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head, root, false);
    }
};