class Solution {
public:
    /*
    // 1. Brute Force 
    // Time: O(n^2)
    // Space: O(1)
    #include <vector>
    vector<int> twoSum(vector<int>& nums, int target) {
        // Always assume there's exactly one solution
        // Cannot reuse the same element twice
        // Return the index of the pairs, therefore we cannot sort because that would change the initial indexes
        // Can return answer in any order

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    return { i, j };
                }
            }
        }
        // return -1 to indicate index was not found, despite the assumption each input will have exactly one solution
        return {-1, -1};
    }
    */

    // 2. Hash Map - Two Pass
    // Time: O(n+n) = O(n)
    // Space: O(n)
    /*
    #include <unordered_map>
    #include <vector>
    vector<int> twoSum(vector<int>& nums, int target) {
        // Always assume there's exactly one solution
        // Cannot reuse the same element twice
        // Return the index of the pairs, therefore we cannot sort because that would change the initial indexes
        // Can return answer in any order

        
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end() && mp.find(complement)->second != i) {
                int firstIdx = mp.find(complement)->second;
                int secondIdx = i;
                return {firstIdx, secondIdx};
            }
        }

        // return -1 to indicate index was not found, despite the assumption each input will have exactly one solution
        return {-1, -1};
    }
    */

    // 3. Hash Map - One Pass (Optimal)
    // Time: O(n)
    // Space: O(n)
    #include <unordered_map>
    #include <vector>
    vector<int> twoSum(vector<int>& nums, int target) {
        // Always assume there's exactly one solution
        // Cannot reuse the same element twice
        // Return the index of the pairs, therefore we cannot sort because that would change the initial indexes
        // Can return answer in any order

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            // Since we first look for the current element's pair in our map and then insert the current element we can be assured that we will not use the same element for our solution
            if (mp.find(target-nums[i]) != mp.end()) {
                int complement = target - nums[i];
                int firstIdx = mp.find(complement)->second;
                int secondIdx = i;
                return {firstIdx, secondIdx};
            }
            mp[nums[i]] = i;
        }

        // return -1 to indicate index was not found, despite the assumption each input will have exactly one solution
        return {-1, -1};
    }
};