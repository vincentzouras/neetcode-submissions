class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Would not have come up with on my own
        
        Use prefix and suffix technique
        1. Move left to right, storing product of all nums to the left of curr index (exclusive)
        2. Then move right to left, storing product of all nums to the right of curr index 
        3. Get result vector by taking product of previous vectors at each index

        To save space, we can use result vector to store prefix, and a single
        variable to store suffix as we calculate final result
        */
        int n = nums.size();
        
        // prefix pass, fill result with prefix
        vector<int> result(n, 1);
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix; // result = prefix * suffix, result currently holds prefix
            suffix *= nums[i]; // suffix we accumulate product of nums as we iterate
        }

        return result;
    }
};
