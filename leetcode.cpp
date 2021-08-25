//stock buy and sell - K transactions allowed

int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<int>> dp(k+1,vector<int> (n,0));
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                int maxi = INT_MIN;
                for(int k=0;k<j;k++)maxi = max(maxi,dp[i-1][k] + prices[j]-prices[k]);
                dp[i][j] = max(dp[i][j-1],maxi);
            }
        }
        return dp[k][n-1];
}

// better solution O(n*k) and linear space
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(k+1,INT_MIN),sell(k+1,INT_MIN);
        buy[0]=0;sell[0]=0;
        int ans = INT_MIN;
        for(auto p:prices)
        {
            for(int i=1;i<=k;i++)
            {
                sell[i] = max(sell[i],buy[i]+p);
                ans = max(ans,sell[i]);
                buy[i] = max(buy[i],sell[i-1]-p);
            }
        }
        return max(ans,0);
}
