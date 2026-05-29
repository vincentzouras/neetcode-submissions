class Solution {
public:
    void dfs(vector<vector<int>>& heights, 
             vector<vector<bool>>& visited,
             int prev_height, int r, int c) {
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size()) {
            return;
        }
        if (visited[r][c]) return;
        if (prev_height > heights[r][c]) return;

        visited[r][c] = true;

        dfs(heights, visited, heights[r][c], r+1, c);
        dfs(heights, visited, heights[r][c], r-1, c);
        dfs(heights, visited, heights[r][c], r, c+1);
        dfs(heights, visited, heights[r][c], r, c-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> pac_visited(m, vector<bool>(n, false));
        vector<vector<bool>> atl_visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; r++) {
            dfs(heights, pac_visited, heights[r][0], r, 0);
            dfs(heights, atl_visited, heights[r][n-1], r, n-1);
        }
        for (int c = 0; c < n; c++) {
            dfs(heights, pac_visited, heights[0][c], 0, c);
            dfs(heights, atl_visited, heights[m-1][c], m-1, c);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pac_visited[r][c] && atl_visited[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
