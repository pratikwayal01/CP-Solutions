//  Not My Code

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
    int store[100001];
    int leftMaxHeight[100001];
    int rightMaxHeight[100001];
    vector<int> result;
    int currentMaxHeight;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        currentMaxHeight = INT_MIN;
        computeLeftHeights(root);
        currentMaxHeight = INT_MIN;
        computeRightHeights(root);
        calculateAnswers(root);

        for (int node : queries)
            result.push_back(store[node]);

        return result;
    }

    void computeLeftHeights(TreeNode* root, int height = 0) {
        if (!root)
            return;

        leftMaxHeight[root->val] = currentMaxHeight;

        if (!root->left && !root->right)
            currentMaxHeight = max(currentMaxHeight, height);

        computeLeftHeights(root->left, height + 1);
        computeLeftHeights(root->right, height + 1);
    }

    void computeRightHeights(TreeNode* root, int height = 0) {
        if (!root)
            return;

        rightMaxHeight[root->val] = currentMaxHeight;

        if (!root->left && !root->right)
            currentMaxHeight = max(currentMaxHeight, height);

        computeRightHeights(root->right, height + 1);
        computeRightHeights(root->left, height + 1);
    }

    void calculateAnswers(TreeNode* root, int height = -1) {
        if (!root)
            return;

        store[root->val] = max(max(height, leftMaxHeight[root->val]), rightMaxHeight[root->val]);

        if (!root->left && !root->right)
            return;

        calculateAnswers(root->left, height + 1);
        calculateAnswers(root->right, height + 1);
    }

};