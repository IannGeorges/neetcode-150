class Solution {
public:
    // 1. Heap Approach
    // n = length of vector, k = top k numbers
    // Time: O(n*log*k) 
    // Space: O(n+k) - hash map size + k elements in minHeap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // keep track of number frequency with a map
        // then iterate over map and store values in a priority queue - expensive insertion (n*log*n) 
        // we can instead make it a minHeap to ensure n*log*k instead of n*log*n and pop the top min element if the heap size is greater than k
        
        // can return answer in any order
        // guaranteed - 0 < k < nums.size(), and that the answer is unique
        // return early if k is equal to the vector size
        if (k == nums.size()) return nums;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> maxHeap;
        for (auto& i : nums) {
            if (freq.find(i) != freq.end()) {
                freq[i]++;
            } else {
                freq[i] = 0;
            }
        }

        for (auto& i : freq) {
            maxHeap.push({i.second, i.first});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        int i = k;
        vector<int> ans;
        while (i > 0) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            i--;
        }
        return ans;
    }

    // 2. Bucket Sort
    // n = length of vector, k = top k numbers
    // Time: O(n) 
    // Space: O(n) - hash map size 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // keep track of number frequency with a map
        // since the max frequency can be up to nums.size(), we can create nums.size() number of buckets to store each number by their frequency in a vector
        // then we can iterate from the end of the array to ensure we will get the first k top elements
        
        // can return answer in any order
        // guaranteed - 0 < k < nums.size(), and that the answer is unique
        // return early if k is equal to the vector size
        if (k == nums.size()) return nums;
        unordered_map<int, int> freq;
        vector<int> ans;
        // add plus 1 we disregard 0 frequencies AND because there could be a frequency with the count of n 
        vector<vector<int>> buckets (nums.size()+1);
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) != freq.end()) {
                freq[nums[i]]++;
            } else {
                freq[nums[i]] = 1;
            }
        }
        for (auto& i : freq) {
            buckets[i.second].push_back(i.first);
        }

     

        for (int i = buckets.size()-1; ans.size() < k ; i--) {
            for (int j = buckets[i].size()-1; j >= 0; j--) {
                ans.push_back(buckets[i][j]);
            }
        }
        
        return ans;
    }
};