class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // swap val at [i][j] with [j][i]
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // reverse each list 
        for (vector<int>& vec : matrix) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                int temp = vec[left];
                vec[left] = vec[right];
                vec[right] = temp;
                left++;
                right--;
            }
        }
    }
};
