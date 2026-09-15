class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> graph(n);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(0);

        vector<bool> visited(n);

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            visited[node] = true;

            for (int nei : graph[node]) {
                if (visited[nei]) continue;
                q.push(nei);
            }
        }

        return count == n;
    }
};
