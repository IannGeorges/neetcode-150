#include <vector>
#include <unordered_set>
#include <algorithm>

 // Hash Set - search for sequence minumum and increment count for every value+1 above the current value
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int answer = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        for(int num : numSet) {
            if(numSet.find(num - 1) == numSet.end()) {
                int count = 1;
                int x = num;
                while(numSet.find(x + 1) != numSet.end()) {
                    count++;
                    x = x + 1;
                }
                answer = max(answer, count);
            }
        }
        
        return answer;
    }
};
