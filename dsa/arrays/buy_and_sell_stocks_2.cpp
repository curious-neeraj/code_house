// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int days = prices.size();

        for(int i = 0; i < days-1; i++)
        {
            if(prices[i+1] > prices[i])
                profit += (prices[i+1] - prices[i]);
        }

        return profit;
    }
};
