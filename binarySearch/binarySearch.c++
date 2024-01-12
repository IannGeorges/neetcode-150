class Solution {
public:
    // Binary Search - Hi- Lo guess gaming 
    // Time: O(logn)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            // Prevents integer overflow 
            int mid = left + (right-left) / 2;
            //int mid = (left+right)/2;
            if (nums[mid] == target) {
                ans = mid;
                return ans;
            } else if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return ans;
    }
};