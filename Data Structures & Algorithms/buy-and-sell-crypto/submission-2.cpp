class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int max_profit = 0; 
        int lowest_price = prices[0];
        for (int price : prices) {
            max_profit = max(max_profit, price - lowest_price);
            lowest_price = min(lowest_price, price);
        }

        return max_profit;
    }
};
