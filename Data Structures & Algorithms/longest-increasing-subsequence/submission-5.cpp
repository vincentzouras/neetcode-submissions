class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> tails; 
        tails.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            int num = nums[i];

            if (num > tails.back()) {
                tails.push_back(num);
                continue;
            } else if (num == tails.back()) {
                continue;
            } else {
                // binary search to find where it goes
                int left = 0;
                int right = tails.size();
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (num > tails[mid]) left = mid + 1;
                    else right = mid;
                }
                // left points at index to replace
                tails[left] = num;
            }
        }

        return tails.size();
    }
};
