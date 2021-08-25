//stock buy and sell - K transactions allowed

int maxProfit(vector<int>& prices) {
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
