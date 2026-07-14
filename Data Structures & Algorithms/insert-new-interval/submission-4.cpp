class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // add intervals with ending smaller then new start to result
        for (; i < n; i++) {
            if (intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else break;
        }

        // merge intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // insert newInterval
        result.push_back(newInterval);

        // copy remaining
        for (; i < n; i++) {
            result.push_back(intervals[i]);
        }

        return result;
    }
};
