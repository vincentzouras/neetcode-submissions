class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Would not have come up with on my own
        
        Use prefix and suffix technique
        1. Move left to right, storing product of all nums to the left of curr index (exclusive)
        2. Then move right to left, storing product of all nums to the right of curr index 
        3. Get result vector by taking product of previous vectors at each index

        To save space, we can only use a result vector and for our second pass
        save previous values instead of adding to another new array
        */
        int n = nums.size();
        
        vector<int> result(n);
        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int prev = nums[n - 1];
        nums[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            int temp = nums[i];
            nums[i] = nums[i + 1] * prev;
            prev = temp;
        }

        for (int i = 0; i < n; i++) {
            result[i] = nums[i] * result[i];
        }

        return result;
    }
};
