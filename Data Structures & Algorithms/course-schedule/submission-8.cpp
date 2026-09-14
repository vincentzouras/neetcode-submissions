class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (vector<int> prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
        }

        vector<int> state(numCourses); // 0 unvisited, 1 visiting, 2 visited

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(graph, state, i)) return false;
        }

        return true;
    }

    bool hasCycle(vector<vector<int>> &graph, vector<int> &state, int course) {
        if (state[course] == 2) return false;
        if (state[course] == 1) return true;

        state[course] = 1;

        for (int nextCourse : graph[course]) {
            if (hasCycle(graph, state, nextCourse)) return true;
        }

        state[course] = 2;

        return false;
    }
};
