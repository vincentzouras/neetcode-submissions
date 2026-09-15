class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> graph(n);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        int count = 0;

        dfs(graph, visited, count, 0);

        return count == n;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int &count, int node) {
        if (visited[node]) return;

        visited[node] = true;
        count++;

        for (int nei : graph[node]) {
            dfs(graph, visited, count, nei);
        }
    }
};
