class Solution {
public:
    // Hash Set
    // Time: O(n^2)
    // Space: O(n^2)
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> cols;
        set<char> rows;
        vector<unordered_set<char>> box(9);
        // check rows & cols by checking if the element exists in each respective set
        // check sub-boxes by using i & j to round down to 0-8 for each sub-box and store the elements in the set that exists within that index
   
        for (int i = 0; i < board.size(); i++) {
            cols.clear();
            rows.clear();
            for (int j = 0; j < board[i].size(); j++) {
                char valRow = board[j][i];
                char valCol = board[i][j];
                if (valCol != '.' && cols.find(valCol) != cols.end()) {
                    return false;
                }
                cols.insert(valCol);
                if (valRow != '.' && rows.find(valRow) != rows.end()) {
                    return false;
                }
                rows.insert(valRow);
                int idx = (i/3)*3+ j/3;
                if (valCol != '.' && box[idx].find(valCol) != box[idx].end()) {
                    return false;
                }
                box[idx].insert(valCol);
            }
        }
    return true;
        
    }
};