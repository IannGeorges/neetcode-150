class Solution {
public:
    // 1. DP - Tabulation
    // Time: O(n)
    // Space: O(n)
    // Intuition: Idea is for every index find the left max (prefix-max) & the right max (postfix-max) for every single index and store these values in an array for each respective pre & post operation. 
    // Then proceed by taking the min of each array for the current index and subtract that from the current index and add it to the sum if the difference is greater than 0.
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftH(n);
        vector<int> rightH(n);
        leftH[0] = 0;
        rightH[n-1] = 0;
        int sum = 0;
        int maxH = INT_MIN;
        // leftMax - prefixMax
        for (int i = 1; i < n; i++) {
            maxH = max(height[i-1], maxH);
            leftH[i] = maxH;
        }

        maxH = INT_MIN;
        // rightMax - postfixMax
        for (int i = n-2; i >=0; i--) {
            maxH = max(height[i+1], maxH);
            rightH[i] = maxH;
        }
        int minH;   
        for (int i = 0; i < n; i++) {
            minH = min(leftH[i], rightH[i]);
            if (minH-height[i] > 0) {
                sum += minH-height[i];
            }
        }

        return sum;
    }

    // 2. Two Pointers
    // Time: O(n)
    // Space: O(1)
    // Intuition: Instead of storing all the pre & post fix max for each index we can utilize two pointers
    // By setting left & right ptrs at the start and end of the array, we can store the pre & post fix max for each respective pointer
    // Then we can increment/decrement the pointer with the smaller pre/post fix value and subtract the the current element
    // If the difference of the pre/post max - height[i] is greater than 0, add it to our sum.
    int trap(vector<int>& height) {
        int sum = 0;
        int left = 0;
        int right = height.size()-1;
        int maxL = height[left];
        int maxR = height[right];
        
        while (left < right) {
            maxL = max(height[left], maxL);
            maxR = max(height[right], maxR);
            if (maxL < maxR) {
                left++;
                int tempSum = maxL - height[left];
                sum += tempSum > 0 ? tempSum : 0;
            } else {
                right--;
                int tempSum = maxR  - height[right];
                sum += tempSum > 0 ? tempSum : 0;
            }
        }

        return sum;
    }
};


