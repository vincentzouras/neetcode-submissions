/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), 
            [](const Interval &a, const Interval &b){
                return a.start < b.start; 
            });
        
        auto cmp = [](const int &a, const int &b){
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> ongoing;
        ongoing.push(intervals[0].end);
        int result = 1;
        
        for (int i = 1; i < n; i++) {
            while (!ongoing.empty() && intervals[i].start >= ongoing.top()) {
                // doesnt overlap
                ongoing.pop();
            }

            ongoing.push(intervals[i].end);
            result = max(result, (int)ongoing.size());
        }

        return result;
    }
};
