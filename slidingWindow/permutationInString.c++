class Solution {
public:
    // 1. Hash Map Freq Count approach 
    // Time:  = O(26n) = O(n)
    // Space: O(m+n)
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return false;
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
            
        }

        int left = 0;
        int right = s1.size();
        
        if (count1 == count2) {
                return true;
        }

        
        while (right < s2.size()) {
            count2[s2[left]-'a']--;
            left++;
            count2[s2[right]-'a']++;
            right++;
            if (count1 == count2) {
                return true;
            }
        }

        return false;
    }

    // 2. Hash Map freq count + initialize & keep track of matches approach 
    // Time:  = O(n)
    // Space: O(m+n)
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return false;
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }

        int left = 0;
        int right = s1.size();
        int matches = 0;

        for (int i = 0; i < count1.size(); i++) {
            matches += count1[i] == count2[i] ? 1 : 0;
        }

        while (right < s2.size()) {
            if (matches == 26) return true;

            int idx = s2[right]-'a';
            count2[idx] += 1;
            if (count1[idx] == count2[idx]) {
                matches += 1;
            } else if (count1[idx]+1 == count2[idx]) {
                matches -= 1;
            }

            idx = s2[left]-'a';
            count2[idx] -= 1;
            if (count1[idx] == count2[idx]) {
                matches += 1;
            } else if (count1[idx]-1 == count2[idx]) {
                matches -= 1;
            }
            left++;
            right++;
        }
        
        return matches == 26;
    }
};
