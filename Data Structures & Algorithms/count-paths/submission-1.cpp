class Solution {
public:
    int dfs(vector<vector<int>> &memo, int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m == 0 && n == 0) return 1;
        if (memo[m][n] != 0) return memo[m][n];

        int go_up = dfs(memo, m-1, n);
        int go_left = dfs(memo, m, n-1);

        memo[m][n] = go_up + go_left;

        return go_up + go_left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0)); 
        // memo[i][j] = # unique paths from i,j which reach 0,0

        return dfs(memo, m-1, n-1);
    }

    /*
    Time complexity: O(2^m+n)
    */
};
