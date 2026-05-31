class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &memo, unordered_set<int> &path, int course) {
        if (path.contains(course)) return true; // cycle
        if (memo[course]) return false;

        path.insert(course);
        
        for (int prereq : graph[course]) {
            if (dfs(graph, memo, path, prereq)) return true;
        }

        memo[course] = true;
        path.erase(course);

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> memo(numCourses, false);

        for (vector<int> &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph[course].push_back(prereq); // what are the prereqs to this course
        }

        for (int course = 0; course < graph.size(); course++) {
            unordered_set<int> path; 
            if (dfs(graph, memo, path, course)) return false;
        }

        return true;
    }
};
