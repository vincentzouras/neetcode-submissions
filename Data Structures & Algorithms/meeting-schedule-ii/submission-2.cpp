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
        sort(intervals.begin(), intervals.end(), 
            [](const Interval &a, const Interval &b){
                return a.start < b.start;
            });
        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (Interval &interval : intervals) {
            if (!minHeap.empty() && minHeap.top() <= interval.start) {
                // ends before next meeting
                minHeap.pop();
            }

            minHeap.push(interval.end);
        }

        return minHeap.size();
    }
};
