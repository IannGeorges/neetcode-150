class Solution {
public:
    // 1. Backtrack DFS Method, leverage recursion (stack) to prune invalid parentheses & store valid parentheses
    // Time:  = O(h) = height of tree = 2^n * n (times n because each recursive call we create a new string which at worst can be 2n)
    // Space: O(h+n*2)
    void helper(vector<string>& arr, int n, int open, int close, string par) {
        // if open && close == n, append resulting string to arr
        if (open == n && close == n) {
            arr.push_back(par);
            return;
        }
        // if open < n, add open brack
        if (open < n) {
            helper(arr, n, open+1, close, par+"(");
        }
        // if open > close add close brack
        if (open > close) {
            helper(arr, n, open, close+1, par+")");
        }
        
    }
    vector<string> generateParenthesis(int n) {
        // think about valid parentheses and reverse engineer it
        vector<string> arr;
        int open = 0;
        int close = 0;
        string par = "";
        helper(arr, n, open, close, par);

        return arr;
    }
};