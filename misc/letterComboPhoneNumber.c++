class Solution {
public:
    void dfs(string digits, map<char, string>& mp, vector<string>& arr, string combo) {
        // completed phone number combo
        if (digits.empty()) {
            arr.push_back(combo);
            return;
        }
        char currDigit = digits[0];
        string letters = mp[currDigit];
        string temp = digits;
        temp.erase(0,1);
        for (auto ch : letters) {
           string newCombo = combo + ch;
           dfs(temp, mp, arr, newCombo); 
        }
    }

    vector<string> letterCombinations(string digits) {
        // create hashmap with number mappings
        // recursively perform dfs 
        // whenever current string is equal to length of the phone number append it to resulting vector
        vector<string> arr;
        string combo = "";
        if (digits.empty()) return arr;
        map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
                                {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, 
                                {'8', "tuv"}, {'9', "wxyz"}};
        

        dfs(digits, mp, arr, combo);

        return arr;
    }
};