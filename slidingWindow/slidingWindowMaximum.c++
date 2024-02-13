class Solution {
public:
    // 1. Monotonically Decreasing Deque 
    // Time:  = O(n)
    // Space: O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> deck;
    int left = 0;
    int right = 0;

    while (right < nums.size()) {
        // while the deque is not empty && deque is not monotonically decreasing pop back
        while (!deck.empty() && nums[deck.back()] < nums[right]) {
            deck.pop_back();
        }
        // push current idx, once the deque is monotonically deque
        deck.push_back(right);

        // if the oldest element in queue is out of our window's scope, pop
        if (left > deck.front()) {
            deck.pop_front();
        }

        // once our window is atleast k length start adding values to our resulting array
        if (right+1 >= k) {
            ans.push_back(nums[deck.front()]);
            left++;
        }
        right++;
        }    
        return ans;
    }
    
    // 2. Brute Force approach - Time Limit Exceeded
    // Time:  = O(k(n-k))
    // Space: O(n-k+1)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // Loop over the entire array
        for (int i = 0; i <= nums.size() - k; i++) {
            int maxVal = INT_MIN;
            // Loop to find the max value in the current window
            for (int j = i; j < i + k; j++) {
                maxVal = max(maxVal, nums[j]);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};