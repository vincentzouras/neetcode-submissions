class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Would not have come up with on my own
        
        Use prefix and suffix technique
        1. Move left to right, storing product of all nums to the left of curr index (exclusive)
        2. Then move right to left, storing product of all nums to the right of curr index 
        3. Get result vector by taking product of previous vectors at each index
        */
        int n = nums.size();
        
        vector<int> prefix(n);
        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        vector<int> suffix(n); 
        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};
