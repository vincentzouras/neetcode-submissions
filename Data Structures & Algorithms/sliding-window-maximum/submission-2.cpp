class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> dq; // montonic decreasing, stores indices
        dq.push_back(0);

        int r = 1;
        for (; r < k; r++) {
            while (!dq.empty() && nums[r] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);
        }

        result.push_back(nums[dq.front()]);

        for (int l = 0; r < n; l++) {
            while (!dq.empty() && nums[r] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);

            while (dq.front() <= l) {
                dq.pop_front();
            }
            result.push_back(nums[dq.front()]);

            r++;
        }

        return result;
    }
};
