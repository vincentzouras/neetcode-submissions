class Solution {
public:
    void dfs(vector<vector<int>> &graph, 
             vector<bool> &visited,
             int node, int parent) {
        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            if (visited[neighbor]) continue;
            dfs(graph, visited, neighbor, node);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (vector<int> edge : edges) { 
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        } 

        vector<bool> visited(n, false); 

        int count = 0;
        for (int node = 0; node < n; node++) {
            if (!visited[node]) count++;
            dfs(graph, visited, node, -1);
        }

        return count;
    }
};
