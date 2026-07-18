class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        vector<vector<bool>> visited(m, vector<bool>(n));

        int dir = 0;
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int r = 0;
        int c = 0;
        for (int i = 0; i < m * n; i++) {
            result.push_back(matrix[r][c]);
            visited[r][c] = true;

            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nc < 0 || nr == m || nc == n || visited[nr][nc]) {
                dir = (dir + 1) % 4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }

            r = nr;
            c = nc;
        }

        return result;
    }
};
