class Solution {
public:
    int dfs(vector<int> &coins, vector<int> &memo, int remaining) {
        if (remaining == 0) return 0;
        if (remaining < 0) return INT_MAX;
        if (memo[remaining] != 0) return memo[remaining];

        int fewest = INT_MAX;

        for (int coin : coins) {
            int result = dfs(coins, memo, remaining - coin);

            if (result != INT_MAX) {
                fewest = min(fewest, 1 + result);
            }
        }

        memo[remaining] = fewest;

        return fewest;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1);
        int fewest = dfs(coins, memo, amount); // how many coins do i still need
        if (fewest == INT_MAX) return -1;
        return fewest;
    }
};
