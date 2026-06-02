class Solution {
public:
    bool existsCycle(vector<vector<int>> &graph, 
                     vector<bool> &visited, 
                     int node, int parent) {
        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            if (visited[neighbor]) return true;
            if (existsCycle(graph, visited, neighbor, node)) return true;
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); // index = node, vector = neighbors

        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        if (existsCycle(graph, visited, 0, -1)) return false;

        for (bool seen : visited) {
            if (!seen) return false; // dfs didnt reach all nodes, disconnected
        }

        return true;
    }
};
