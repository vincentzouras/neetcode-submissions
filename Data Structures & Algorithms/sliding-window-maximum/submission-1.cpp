class Solution {

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        auto cmp = [](pair<int, int> &a, pair<int, int> &b){
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       decltype(cmp)> pq(cmp); 

        int r = 0;
        for (; r < k; r++) {
            pq.push({nums[r], r});
        }

        result.push_back(pq.top().first);

        for (int l = 0; r < n; l++) {
            pq.push({nums[r], r});

            while (pq.top().second <= l) {
                pq.pop();
            }
            
            result.push_back(pq.top().first);

            r++;
        }

        return result;
    }
};
