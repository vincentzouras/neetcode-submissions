class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        /*
        width = j - i 
        height = min of heights[i]
        */
        int i = 0;
        int j = n - 1;
        int max_water = 0;
        while (i < j) {
            int curr_water = (j - i) * min(heights[i], heights[j]);
            max_water = max(max_water, curr_water);

            // pick pointer to move
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_water; 
    }
};
