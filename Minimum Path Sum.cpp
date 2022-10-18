class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--)
        for(int j=n-1;j>=0;j--)
            if(dp[i][j]==INT_MAX)
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
        return dp[0][0];
    }
};
