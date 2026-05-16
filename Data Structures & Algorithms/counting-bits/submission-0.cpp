class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for (int i = 0; i <= n; i++) {
            int ones = 0;
            int x = i; 
            while (x > 0) {
                ones += x & 1;
                x >>= 1;
            }
            output.push_back(ones);
        } 
        return output;
    }
};
