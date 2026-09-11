class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minutes = 0;
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }
        }

        const vector<pair<int, int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {
            int layer = q.size();
            bool changed = false;
            for (int i = 0; i < layer; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n 
                        && grid[nr][nc] == 1) {
                        changed = true;
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            if (changed) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
