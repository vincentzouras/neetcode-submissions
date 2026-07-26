class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int level = 1;
        int max_height = height[0];
        int waters = 0;

        for (int h : height) {
            max_height = max(max_height, h);
        }

        while (level <= max_height) {
            int left = 0;
            int right = n - 1;
            while (height[left] < level) left++;
            while (height[right] < level) right--;

            while (left < right) {
                if (height[left] < level) waters++;
                left++;
            }

            level++;
        }

        return waters;
    }
};