/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root==nullptr) {
            return root;
        }  
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            map<TreeNode*, int> siblingSumMap;
            int levelSum = 0;
            queue<TreeNode*> tempQueue;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                tempQueue.push(node);
                if (node->left) {
                    siblingSumMap[node] += node->left->val;
                    levelSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    siblingSumMap[node] += node->right->val;
                    levelSum += node->right->val;
                    q.push(node->right);
                }
            }
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = tempQueue.front();
                tempQueue.pop();

                if (node->left) {
                    node->left->val = levelSum - siblingSumMap[node];
                }
                if (node->right) {
                    node->right->val = levelSum - siblingSumMap[node];
                }
            }
        }
        root->val = 0;
        return root;
    }
};