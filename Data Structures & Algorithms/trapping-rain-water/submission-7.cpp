class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waters = 0;

        int left = 0;
        int leftMax = height[left];
        int right = n - 1;
        int rightMax = height[right];

        while (left <= right) { 
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                waters += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                waters += rightMax - height[right];
                right--;
            }
        }

        return waters;
    }
};
