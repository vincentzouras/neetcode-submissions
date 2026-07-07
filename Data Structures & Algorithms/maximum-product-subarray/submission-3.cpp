class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prev_max = nums[0];
        int prev_min = nums[0];
        int max_product = nums[0];

        for (int i = 1; i < n; i++) {
            int start_new = nums[i];
            int pos_max = nums[i] * prev_max;
            int neg_max = nums[i] * prev_min;
            prev_max = max({start_new, pos_max, neg_max});
            prev_min = min({start_new, pos_max, neg_max});
            max_product = max(max_product, prev_max);
        }

        return max_product;
    }
};
