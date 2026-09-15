class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        int count = 0;

        return !hasCycle(graph, visited, count, -1, 0) && count == n;
    }

    bool hasCycle(vector<vector<int>> &graph, vector<bool> &visited, int &count, int prev, int node) {
        if (visited[node]) return true;

        visited[node] = true;
        count++;

        for (int nei : graph[node]) {
            if (nei == prev) continue;
            if (hasCycle(graph, visited, count, node, nei)) return true;
        }

        return false;
    }
};
