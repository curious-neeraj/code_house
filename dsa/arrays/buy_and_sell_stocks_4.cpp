// Time Complexity - O(n * k)
// Space Complexity - O(k)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int days = prices.size();

        vector<int> min_price(k, INT_MAX);
        vector<int> max_profit(k, 0);
        
        for(int i = 0; i < days; i++)
        {
            for(int j = 0; j < k; j++)
            {
                min_price[j] = min(min_price[j], 
                                   prices[i] - (j > 0 ? max_profit[j-1] : 0));
                max_profit[j] = max(max_profit[j], 
                                    prices[i] - min_price[j]);
            }
        }
        return max_profit[k-1];
    }
};
