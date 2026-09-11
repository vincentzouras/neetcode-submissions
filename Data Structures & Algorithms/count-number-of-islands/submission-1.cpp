class Solution {
public:
    int num = 0;
    int numIslands(vector<vector<char>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    num++;
                    dfs(grid, r, c);
                }
            }
        }

        return num;
    }

    void dfs(vector<vector<char>> &grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return;
        }

        if (grid[r][c] == '0') return;

        grid[r][c] = '0';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
};
