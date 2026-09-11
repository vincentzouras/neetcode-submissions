class Solution {
public:
    int maxArea = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    int currArea = 0;
                    dfs(grid, currArea, r, c);
                } 
            }
        }
        
        return maxArea;
    }

    void dfs(vector<vector<int>> &grid, int &currArea, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || 
            grid[r][c] == 0) {
            maxArea = max(maxArea, currArea);
            return;
        }

        currArea++;
        grid[r][c] = 0;

        dfs(grid, currArea, r+1, c);
        dfs(grid, currArea, r-1, c);
        dfs(grid, currArea, r, c+1);
        dfs(grid, currArea, r, c-1);
    }
};
