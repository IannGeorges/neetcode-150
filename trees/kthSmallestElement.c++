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
// In Order Traversal Approach
// Time: O(N)
// Space: O(1) if considering only variables, if considering stack space O(logn) in a balanced tree & O(n) in unbalance tree
    void helper(TreeNode* root, int k, int& ans, int& count) {
        if (root == NULL) {
            return;
        }
        helper(root->left, k, ans, count);
        count++;
        if (count == k) {
            ans = root->val;
            return;
        }
        helper(root->right, k, ans, count);
    }

    int kthSmallest(TreeNode* root, int k) {
       // if I can recursively print elements from the stack, i can find the k-th smallest element
       int ans;
       int count = 0;
       helper(root, k, ans, count);
       return ans; 
    }
};