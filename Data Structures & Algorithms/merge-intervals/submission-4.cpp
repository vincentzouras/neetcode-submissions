class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &a, const vector<int> &b){
                return a[0] < b[0];
            });

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            // dont merge
            if (intervals[i][0] > result.back()[1]) 
                result.push_back(intervals[i]);
            
            // merge
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }

        return result;
    } 
};
