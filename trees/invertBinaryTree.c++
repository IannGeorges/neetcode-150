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
    // Iterative Solution - BFS
    // Time: O(n)
    // Space: O(n/2) = O(n)
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        deque<TreeNode*> q;
        q.push_back(root);
       
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop_front();
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            if (curr->left != NULL) q.push_back(curr->left);
            if (curr->right != NULL) q.push_back(curr->right);
        }

        return root;
    }
    // Recursive Solution - DFS
    // Time: O(n)
    // Space: O(logn)->O(n) = O(n)
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};