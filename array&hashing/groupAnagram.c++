class Solution {
public:
    // 1. Sort Each Word
    // n = length of vector, k = length of longest string in vector
    // Time: O(n*klogk) - sorting every word in vector
    // Space: O(n*k) - map<string, vector<string>> and storing a temp string (neglible)
    /*
    #include <map>
    #include <vector>
    #include <string>
    #include <algorithm>
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each word and index the sorted word as a key in our map, then if there's a key match append the word to value vector
        // key = sorted word, value = vector of corresponding words

        if (strs.empty()) return {{}};
        map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            mp[word].push_back(strs[i]);
  
        }

        vector<vector<string>> res;
        for (auto& i : mp) {
            res.push_back(i.second);
        }

        return res;
    }
    */

    // 2. Hash Map - Categorizing by Letter Count (Optimal)
    // n = length of vector, k = lenght of longest string in vector
    // Time: O(n*k)
    // Space: O(n*k)

    #include <vector>
    #include <string>
    #include <map>
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map the frequency of letters for each word in a vector
        // key = letter freq, value = vector of corresponding words

        if (strs.empty()) return {{}};
        map<vector<int>, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                // assuming input contains only lowercase lettes
                freq[strs[i][j]-'a']++;
            }
            mp[freq].push_back(strs[i]);
  
        }

        vector<vector<string>> res;
        for (auto& i : mp) {
            res.push_back(i.second);
        }

        return res;
    }
};