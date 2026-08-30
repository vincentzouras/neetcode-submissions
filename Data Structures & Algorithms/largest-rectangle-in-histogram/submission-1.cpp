class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int largest_area = heights[0];
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) { 
                int height = heights[s.top()];
                s.pop();

                int width;
                if (s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }

                largest_area = max(largest_area, width * height);
            }

            s.push(i);
        }

        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();

            int width;
            if (s.empty()) width = n;
            else width = n - s.top() - 1;

            largest_area = max(largest_area, width * height);
        }

        return largest_area;
    }
};
