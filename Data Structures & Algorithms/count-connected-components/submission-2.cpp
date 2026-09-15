class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(graph, visited, i);
            }
        }

        return count;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node) {
        if (visited[node]) return;

        visited[node] = true;

        for (int nei : graph[node]) {
            dfs(graph, visited, nei);
        }
    }
};
