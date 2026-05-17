class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1);
        for (int i = 1; i <= n; i++) {
            output[i] = output[i >> 1] + (i & 1);
        } 
        return output;
    }

    /*
    We observe that the number of 1's in i is equal to the number of 1's in i >> 1, plus
    if the last bit of i is 1 (so i & 1)
    */
};
