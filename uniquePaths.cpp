class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if(i==0 or j==0) return 1;
        return dp[i-1][j] + dp[i][j-1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        dp[i][j] = solve(i,j,dp);
        
        return dp[n-1][m-1];
    }
};
