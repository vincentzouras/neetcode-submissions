class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n-1]) {
                // in this row
                int l1 = 0;
                int r1 = n-1;
                while (l1 <= r1) {
                    int mid1 = l1 + (r1 - l1) / 2;
                    if (target == matrix[mid][mid1]) return true;
                    else if (target > matrix[mid][mid1]) l1 = mid1 + 1;
                    else r1 = mid1 - 1;
                }
                return false;
            } else if (target < matrix[mid][0]) {
                // upper row
                r = mid - 1;
            } else {
                // lower row
                l = mid + 1;
            }
        }

        return false;
    }
};
