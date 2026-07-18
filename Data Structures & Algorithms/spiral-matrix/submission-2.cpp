class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        vector<int> result;

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; c++) {
                result.push_back(matrix[top][c]);
            }
            top++;

            for (int r = top; r <= bottom; r++) {
                result.push_back(matrix[r][right]);
            }
            right--;

            if (top <= bottom) {
                for (int c = right; c >= left; c--) {
                    result.push_back(matrix[bottom][c]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int r = bottom; r >= top; r--) {
                    result.push_back(matrix[r][left]);
                }
                left++;
            }
        }

        return result;
    }
};
