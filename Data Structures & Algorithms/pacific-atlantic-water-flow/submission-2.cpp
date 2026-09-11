class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> reachesPacific(m, vector<bool>(n, false));
        vector<vector<bool>> reachesAtlantic(m, vector<bool>(n, false));


        for (int r = 0; r < m; r++) {
            dfs(heights, reachesPacific, heights[r][0], r, 0);
            dfs(heights, reachesAtlantic, heights[r][n-1], r, n-1);
        }
        for (int c = 0; c < n; c++) {
            dfs(heights, reachesPacific, heights[0][c], 0, c);
            dfs(heights, reachesAtlantic, heights[m-1][c], m-1, c);
        }

        vector<vector<int>> reachesBoth;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (reachesAtlantic[r][c] && reachesPacific[r][c]) {
                    reachesBoth.push_back({r, c});
                }
            }
        }

        return reachesBoth;
    }

    void dfs(vector<vector<int>> &heights, 
             vector<vector<bool>> &reaches, 
             int prevHeight, int r, int c) {
        if (r < 0 || r >= heights.size() || 
            c < 0 || c >= heights[0].size()) return;
        if (reaches[r][c]) return;
        if (heights[r][c] < prevHeight) return;

        reaches[r][c] = true;

        dfs(heights, reaches, heights[r][c], r+1, c);
        dfs(heights, reaches, heights[r][c], r-1, c);
        dfs(heights, reaches, heights[r][c], r, c+1);
        dfs(heights, reaches, heights[r][c], r, c-1);
    }
};
