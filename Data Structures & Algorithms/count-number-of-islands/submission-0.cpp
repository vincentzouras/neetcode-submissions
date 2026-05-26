class Solution {
public:
    void dfs(vector<vector<char>> &grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return;
        if (grid[r][c] == '0') return;

        grid[r][c] = '0';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    num_islands += 1;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
