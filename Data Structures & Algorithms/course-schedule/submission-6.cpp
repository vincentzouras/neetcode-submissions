class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        // Build graph representation 
        for (vector<int> &prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]); // b unlocks a
            indegree[prereq[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (int dest : graph[course]) {
                indegree[dest]--;
                if (indegree[dest] == 0) q.push(dest);
            }
        }

        return count == numCourses;
    }
};
