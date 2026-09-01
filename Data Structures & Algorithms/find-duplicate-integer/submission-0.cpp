class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.contains(num)) return num;
            else {
                seen.insert(num);
            }
        }
    }
};
