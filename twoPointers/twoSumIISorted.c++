class Solution {
public:
    // Two Pointer Method
    // if currSum of nums[left] + nums[right] is greater than target sum, decrement the right pointer
    // if currSum of nums[left] + nums[right] is less than target sum, increment the left pointer
    // if currSum of nums[left] + nums[right] is equal to target sum, return the left & right pointer
    // Time: O(n)
    // Time: O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans (2);
        
        int left = 0;
        int right = numbers.size()-1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left+1, right+1};
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }

        return {-1, -1};
    }
};