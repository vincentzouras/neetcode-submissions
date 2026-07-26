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
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);


            if (height[left] <= height[right]) {
                waters += max(leftMax - height[left], 0);
                left++;
            } else {
                waters += max(rightMax - height[right], 0);
                right--;
            }
        }

        return waters;
    }
};
