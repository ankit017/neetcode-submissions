class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = prices[0];
        int max_profit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > curr_min) {
                max_profit = max(max_profit, prices[i] - curr_min);
            }
            curr_min = min(curr_min, prices[i]);
        }
        return max_profit;
        
    }
};
