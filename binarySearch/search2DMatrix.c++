class Solution {
public:
    // Binary Search on Row, then Binary Search on Col
    // Time: O(logm+logn)
    // Space: O(1)
    bool binarySearch(vector<vector<int>>& matrix, int target, int row) {
        int leftCol = 0;
        int rightCol = matrix[0].size()-1;
        while (leftCol <= rightCol) {
            int midCol = (leftCol+rightCol)/2;
            if (matrix[row][midCol] == target) {
                return true;
            } else if (matrix[row][midCol] > target) {
                rightCol = midCol-1;
            } else {
                leftCol = midCol+1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first check the rows by doing binary search on the first index of the first row and last row 
        // second check the cols by doing binary search on the first & last index of the col
        
        int leftRow = 0;
        int rightRow = matrix.size()-1;
        int leftCol = 0;
        int rightCol = matrix[0].size()-1;

        // find the corresponding row first 
        while (leftRow <= rightRow) {
            int midRow = (leftRow+rightRow)/2;
            if (matrix[midRow][rightCol] < target) {
                leftRow = midRow+1;
            } else if (matrix[midRow][leftCol] > target) {
                rightRow = midRow-1;
            } else {
                return binarySearch(matrix, target, midRow);
            }
        }

        // By now leftRow & rightRow are the same index so we can use either row var to find the index of col
        // find the corresponding col first 

        return false;
    }

    // Binary Search on 1D Array
    // Time: O(logmn)
    // Space: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Treat the matrix as an array
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = (row*col)-1;

        while (left <= right) {
            int mid = (left+right) / 2;
            int midElement = matrix[mid/col][mid%col];
            if (midElement == target) {
                return true;
            } else if (midElement > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return false;

    }
};