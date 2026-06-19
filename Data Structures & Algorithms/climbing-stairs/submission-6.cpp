class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        int one_ago = 1;
        int two_ago = 1;
        
        int curr;
        for (int i = 2; i <= n; i++) {
            curr = one_ago + two_ago;
            two_ago = one_ago;
            one_ago = curr;
        }

        return curr;
    }
};
