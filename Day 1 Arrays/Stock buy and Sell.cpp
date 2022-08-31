// Problem Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#define ll int

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ll mini = prices[0];
        ll ans = 0;
        for(ll i=0;i<prices.size();i++)
        {
            ans = max(ans,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return ans;
    }
};