class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int remainder = target - curr;

            if (seen.contains(remainder)) {
                return vector<int>{seen[remainder], i};
            }

            seen[curr] = i;
        }

        return {};
    }
};
