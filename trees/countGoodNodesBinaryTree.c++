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
    // DFS Pre Order Traversal w/ Global Count & Local Max
    // Time: O(n)
    // Space: O(n)
    void dfs(TreeNode* node, int currMax, int& count) {
        if (node == NULL) return;

        if (currMax <= node->val) {
            count++;
            currMax = node->val;
        }
        dfs(node->left, currMax, count);
        dfs(node->right, currMax, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        int currMax = INT_MIN;
        dfs(root, currMax, count);
        return count;
    }
};