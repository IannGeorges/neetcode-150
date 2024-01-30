class Solution {
public:
    // 1. Monotonic Stack, leverage a monotonic decreasing stack with nested pair to store the {temp, i-th day}. If the current temp is greater than the top element in stack, keep popping, else place temp & i in stack
    // Time:  = O(n)
    // Space: O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        deque<pair<int, int>> stk;
        vector<int> arr(sz, 0);
        if (sz < 1) return arr;

        for (int i = 0; i < sz; i++) {
            int currDay = i;
            int currTemp = temperatures[i];
            while (!stk.empty() && stk.back().second < currTemp) {
                int prevDay = stk.back().first;
                
                int wait = currDay - prevDay;
                arr[prevDay] = wait;
                stk.pop_back();
            }
            stk.push_back({currDay, currTemp});
        }
        return arr;
    }
};