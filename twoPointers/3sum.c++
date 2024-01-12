class Solution {
public:
    // 1.Two Pointer + Sorting Array
    // Time: O(nlogn+n^2) = O(n^2)
    // Space: O(log(n)) -> O(n)
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>& ans) {
        int left = i+1;
        int right = nums.size()-1;
        while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == 0) {
                        ans.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        // to avoid duplicates increment the left index while it's previous index element is a duplicate
                        while (left < right && nums[left] == nums[left-1]) {
                            left++;
                        }
                    } else if (sum > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // while the left most pointer is less than or equal to 0/target, keep looping
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            // if i is on the first index or if the previous index is not a duplicate check for sum
            if (i == 0 || nums[i-1] != nums[i]) {
                twoSumII(nums, i, ans);
            }

        }
        return ans;
    }

    // 2. Hash Set + Sorting
    // Time: O(nlogn+n^2) = O(n^2) - twoSumII() is O(n) and we call it O(n) times
    // Space: O(n) - hash set
    void twoSumII(vector<int>& nums, int i, vector<vector<int>>&ans) {
        set<int> s;
        for (int j = i+1; j < nums.size(); j++) {
            // find the complement that will give us 0/target value
            int comp = -(nums[i]+nums[j]);
            if (s.find(comp) != s.end()) {
                ans.push_back({nums[i], nums[j], comp});
                while (j+1 < nums.size() && nums[j-1] == nums[j]) {
                    j++;
                }
            }
            // why do we only add the right pointer?
            // We add the right pointer because it is expanding our window and to ensure we do not process duplicates
            // This ensure all the elements in our set are within the range of i+1 to j-1
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        // while the left most pointer is less than or equal to 0/target, keep looping
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            // if i is on the first index or if the previous index is not a duplicate check for sum
            if (i == 0 || nums[i-1] != nums[i]) {
                twoSumII(nums, i, ans);
            }

        }
        return ans;
    }

    // 3. Hash Set + No Sort
    // Time: O(n^2) - nested for loops
    // Space: O(n) - hash set

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // to ensure we are always storing unique tuples by sorting them
        set<vector<int>> res;
        // to ensure we don't have duplicate values check the outer loop if the current element isn't in our set
        unordered_set<int> dups;
        // map to find the complement and ensure that the index is unique 
        unordered_map<int, int> seen;
        
        
        for (int i = 0; i < nums.size(); i++) {
            // insert the current element, if the current element for the left most index has not been seen
            if (dups.insert(nums[i]).second) {
                for (int j = i+1; j < nums.size(); j++) {
                    int comp = -(nums[i]+nums[j]);
                    auto it = seen.find(comp);
                    // if the opposite complement of the sum is found and it's idx is the current idx
                    if (it != seen.end() && it->second == i) {
                        vector<int> triplet = {nums[i], nums[j], comp};
                        sort(triplet.begin(), triplet.end());
                        res.insert(triplet);
                    }
                    seen[nums[j]] = i;
                }
            }
        }
        return vector<vector<int>>(begin(res), end(res));
    }
};

class Solution {
public:
   
};