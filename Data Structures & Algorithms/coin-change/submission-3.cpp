class Solution {
public:
    int dfs(vector<int>& coins, vector<int> &memo, int remaining) {
        if (remaining == 0) return 0; // dont need any more coins
        if (remaining < 0) return INT_MAX; // invalid path
        if (memo[remaining] != 0) return memo[remaining];

        int fewest_coins = INT_MAX;

        for (int coin : coins) {
            int result = dfs(coins, memo, remaining - coin);
            if (result != INT_MAX) fewest_coins = min(fewest_coins, result + 1);
        }

        memo[remaining] = fewest_coins;

        return fewest_coins;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1); // we include 0 as a possible state
        int answer = dfs(coins, memo, amount);
        return (answer != INT_MAX) ? answer : -1;
    }
};
