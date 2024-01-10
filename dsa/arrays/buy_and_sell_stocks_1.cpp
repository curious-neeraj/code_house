// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int len = prices.size();
        if(len <= 1)
            return 0;

        int buy = prices[0];
        for(int i = 1; i < len; i++)
        {
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};
