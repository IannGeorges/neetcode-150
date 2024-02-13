/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS Solution Iterative Solution
// Time: O(n)
// Space: O(n)
class Codec {
public:
   // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // check edge case if root is null
        if (!root) return "";

        // initialize string for serialization & queue to process nodes in bfs.
        string ans;
        queue<TreeNode*> q;
        
        // push root into queue to initialize loop
        q.push(root);
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode) {
                // if currNode is not null, process int into our serialized string w/ delimiter & push left & right nodes into queue
                ans += to_string(currNode->val) + " ";
                q.push(currNode->left);
                q.push(currNode->right);
            } else {
                // if node is null, we still process the node w/ delimiter into our serialized string, however we don't push children nodes
                ans += "null ";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // check edges cases if root is null or data is empty return an empty tree (nullptr)
        if (data.empty() || data == "null") return nullptr;

        // initialize input string stream & cast the string to become a stringstream
        istringstream ss(data);
        string value;
        // process first string in string stream, recall the order of precedence iss >> string/int/double/etc.
        ss >> value;
        
        // intialize queue w data type of nodes in order to keep a reference to node's as we build out the tree
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(value));
        q.push(root);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            // process left child
            ss >> value;
            if (value != "null") {
                currNode->left = new TreeNode(stoi(value));
                q.push(currNode->left);
            } 
            // process right child
            ss >> value;
            if (value != "null") {
                currNode->right = new TreeNode(stoi(value));
                q.push(currNode->right);
            }
           
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


// DFS Recursive Solution
// Time: O(n)
// Space: O(n)
class Codec {
public:

    void dfs_encode(TreeNode* node, string &ans) {
        if (node == NULL) {
            ans += "null ";
            return;
        }
        
        ans += to_string(node->val) + " ";
        dfs_encode(node->left, ans);
        dfs_encode(node->right, ans);
    }

    TreeNode* dfs_decode(istringstream& iss) {
        string value;
        iss >> value;

        if (value == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(value));
        root->left = dfs_decode(iss);
        root->right = dfs_decode(iss);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        dfs_encode(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "null ") return nullptr;
        istringstream iss(data);
        TreeNode* root = dfs_decode(iss);
        return root;    
    }
};