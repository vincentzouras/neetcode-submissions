class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (vector<int> prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
        }

        vector<int> state(numCourses); // 0 unvisited, 1 visiting, 2 visited
        vector<int> ordering; 

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(graph, state, ordering, i)) return {};
        }

        reverse(ordering.begin(), ordering.end());

        return ordering;
    }

    bool hasCycle(vector<vector<int>> &graph, vector<int> &state, vector<int> &ordering, int course) {
        if (state[course] == 2) return false;
        if (state[course] == 1) return true;

        state[course] = 1;

        for (int unlocked : graph[course]) {
            if (hasCycle(graph, state, ordering, unlocked)) return true;
        }

        state[course] = 2;
        ordering.push_back(course);
        
        return false;
    }
};
