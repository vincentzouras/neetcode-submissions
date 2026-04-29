class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique_nums(nums.begin(), nums.end()); 

        if (nums.size() == 0) return 0;

        int longest_length = 0;

        for (int num : unique_nums) {
            int curr_length = 0;
            if (!unique_nums.contains(num - 1)) { // start of a sequence
                while (unique_nums.contains(num)) {
                    curr_length++;
                    num++;
                }
                longest_length = max(longest_length, curr_length); 
            }
        }

        return longest_length;
    }
};
