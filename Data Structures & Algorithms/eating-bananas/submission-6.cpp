class Solution {
public:
    bool canFinish(vector<int> piles, int h, int r) {
        for (int pile : piles) {
            h -= (pile + r - 1) / r;
        }
        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); 

        int biggest = piles[0];
        for (int pile : piles) {
            biggest = max(biggest, pile);
        }

        int l = 1;
        int r = biggest; 
        int minSpeed = biggest;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (canFinish(piles, h, m)) {
                minSpeed = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return minSpeed;
    }
};
