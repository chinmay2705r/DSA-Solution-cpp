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
private:
    int matchingNodes = 0;

    std::pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int currentSum = root->val + leftSum + rightSum;
        int currentCount = 1 + leftCount + rightCount;


        if (currentSum / currentCount == root->val) {
            matchingNodes++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodes = 0;
        dfs(root);
        return matchingNodes;
    }
};