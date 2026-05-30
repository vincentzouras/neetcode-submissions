class Solution {
public:
    bool dfs(vector<vector<int>> &graph, unordered_set<int> &path, int course) {
        if (path.contains(course)) return true; // cycle

        path.insert(course);
        
        for (int c : graph[course]) {
            if (dfs(graph, path, c)) return true;
        }

        path.erase(course);

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (vector<int> &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course); // what course does this one unlock
        }

        for (int course = 0; course < graph.size(); course++) {
            unordered_set<int> path; 
            if (dfs(graph, path, course)) return false;
        }

        return true;
    }
};
