class Solution {
public:
    // 1. Sorting
    // Time: O(nlogn)
    // Space: O(1) 
    /*
    #include <string>
    #include <algorithm>
    bool isAnagram(string s, string t) {
        
        // Good practice to always return early if there an initial required condition that is false 
        if (s.size() != t.size()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    */

    // 2. Letter Frequency Counter
    // Time: O(n)
    // Space: O(1) since our vector is a constant size of 26
    #include <string>
    #include <vector>
    bool isAnagram(string s, string t) {
        
        // Good practice to always return early if there an initial required condition that is false 
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> freq(26,0);
        for (int i = 0; i < s.size(); i++) {
            // assuming string s & t only consist of lowercase letters
            freq[s[i]-'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            // assuming string s & t only consist of lowercase letters
            freq[t[i]-'a']--;
            // if the current count ever falls below 0 we know for certain the strings aren't anagram
            if (freq[t[i]-'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};