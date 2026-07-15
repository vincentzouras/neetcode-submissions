class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int result = 0;

        sort(intervals.begin(), intervals.end(), 
            [](const vector<int> &a, const vector<int> &b){
                return a[1] < b[1];
            });

        int prev_end = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prev_end) { // keep it 
                prev_end = intervals[i][1];
            } else { // remove it 
                result++; 
            }
        } 

        return result;
    }
};
