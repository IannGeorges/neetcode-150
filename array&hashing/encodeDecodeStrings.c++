class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto& str : strs) {
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        string temp;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int num = j-i;
            cout << s.substr(i,num) << endl;
            int len = stoi(s.substr(i,num));
            temp = s.substr(j+1, len);
            res.push_back(temp);
            i = j+1+len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));