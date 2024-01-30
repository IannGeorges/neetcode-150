
class Solution {
public:
    // 1. Hash Map Freq Count approach 
    // Time:  = O(2n) = O(n)
    // Space: O(n)
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;

        for (auto num : nums) {
            if (mp.find(num) != mp.end()) {
                mp[num]++;
            } else {
                mp[num] = 1;
            }
        }

        for (auto num : nums) {
            int comp = num+k;
            if (mp.find(comp) != mp.end()) {
                count += mp[comp];
            }
        }

        return count;
    }
};