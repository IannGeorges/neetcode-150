class Solution {
public:
    int lengthOfLongestSubstring(string word) {
        // 1. Sliding Window approach 
        // Time:  = O(n)
        // Space: O(n)
        if (word.size() < 2) return word.size();
        unordered_map<char, int> mp;
        int left = 0;
        int right = 0;
        int maxLength = 0;

        while (right < word.size()) {
            char currChar = word[right];
            if (mp.find(currChar) == mp.end() || mp.find(currChar)->second < 1) {  
                mp[currChar] = 1;
                right++;
                maxLength = max(right-left, maxLength);
            } else {
                mp[word[left]]--;
                left++; 
            }  
        }

        return maxLength;
    }
};