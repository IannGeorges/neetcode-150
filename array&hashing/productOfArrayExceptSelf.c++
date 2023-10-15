class Solution {
public:
    // Prefix & Postfix Arrays
    // Time: O(n+n+n) = O(n)
    // Space: O(n+n+n) = O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        // The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
        int n = nums.size();
        vector<int> pre(n, 0);
        vector<int> post(n,0);
        vector<int> ans(n,0);
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                pre[i] = nums[i];
            } else {
                pre[i] = nums[i]*pre[i-1];
            }
        }

        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                post[i] = nums[i];
            } else {
                post[i] = nums[i]*post[i+1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = post[i+1];
            } else if (i == n-1) {
                ans[i] = pre[i-1];
            } else {
                ans[i] = pre[i-1]*post[i+1];
            }
        }

        return ans;
    }
};