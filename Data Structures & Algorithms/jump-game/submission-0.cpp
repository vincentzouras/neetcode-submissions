class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            int distance = goal - i;
            if (nums[i] >= distance) goal = i;
        }
        
        return goal == 0;
    }
};
