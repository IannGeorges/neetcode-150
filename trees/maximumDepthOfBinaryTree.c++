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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        deque<pair<TreeNode*, int>> q;
        int maxDep = 0;
        q.push_back({root, 1});
        while (!q.empty()) {
            TreeNode* currNode = q.front().first;
            int currDepth = q.front().second;
            q.pop_front();
            maxDep = max(maxDep,currDepth);
            if (currNode->left != NULL) {
                q.push_back({currNode->left, currDepth+1});
            }
            if (currNode->right != NULL) {
                q.push_back({currNode->right, currDepth+1});
            }
        }
        return maxDep;
    }
    // Recursive Solution - DFS
    // Time: O(n)
    // Space: O(logn)->O(n) = O(n)
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return max(1+maxDepth(root->left), 1+maxDepth(root->right));
    }
};
