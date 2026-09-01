class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int curr = 0;

        while (true) {
            if (nums[curr] < 0) return curr;
            nums[curr] = -nums[curr];
            curr = -nums[curr];
        }
    }
};
