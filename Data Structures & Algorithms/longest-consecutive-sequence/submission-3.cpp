class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique_nums(nums.begin(), nums.end()); 

        if (nums.size() == 0) return 0;

        int longest_length = 0;

        for (int curr : unique_nums) {
            // skip if not start of sequence
            if (unique_nums.contains(curr - 1)) continue; 
            
            int curr_length = 0;
            while (unique_nums.contains(curr)) {
                curr_length++;
                curr++;
            }
            
            longest_length = max(longest_length, curr_length); 
        }

        return longest_length;
    }
};
