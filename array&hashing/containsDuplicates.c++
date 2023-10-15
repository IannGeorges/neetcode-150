class Solution {
public:
    // 1. Brute Force - Time Limit Exceeded
    // Time: O(n^2)
    // Space: O(1)
    /*
    #include <vector>
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
    */

    // 2. Sorting 
    // Time: O(nlogn+n) = O(nlogn)
    // Space: O(1)
    /*
    #include <vector>
    #include <algorithm>
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) {
                return true;
            }
        }

        return false;
    }
    */

    // 3. Hash Set 
    // Time: O(n)
    // Space: O(n)
    
    #include <vector>
    #include <set>
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }
};