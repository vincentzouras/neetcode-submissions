class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        vector<vector<bool>> visited(m, vector<bool>(n));

        int r = 0;
        int c = 0;
        int dir = 0; // 0 = right, 1 = down, 2 = left, 3 = up
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        for (int i = 0; i < m*n; i++) {
            // collect current cell
            result.push_back(matrix[r][c]);
            visited[r][c] = true;

            // where would i go next?
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            // can i go there?
            if (nr < 0 || nc < 0 || nr == m || nc == n || visited[nr][nc]) {
                // no, turn
                dir = (dir + 1) % 4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }

            // move
            r = nr;
            c = nc;
        }

        
        return result;
    }
};
