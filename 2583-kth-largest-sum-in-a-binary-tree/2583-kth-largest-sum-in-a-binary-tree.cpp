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
    long long kthLargestLevelSum(TreeNode* root, int k) {
         if (root==nullptr) {
            return -1;
         }
        queue<TreeNode*> q;  
        vector<long long> levelSums; 
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size(); 
            long long levelSum = 0;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;  
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            levelSums.push_back(levelSum);  
        }
        sort(levelSums.begin(), levelSums.end(), std::greater<long long>());
        if (k > levelSums.size()) return -1;
        return levelSums[k - 1];
    }
};