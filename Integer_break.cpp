//Question-link: https://leetcode.com/problems/integer-break/

class Solution {
public:
    
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp,n);
    }
    int solve(int n, vector<int> &dp,int N){
            if(n==1|| n==0)
                return 1;
        if(dp[n]!=-1)
            return dp[n];
        int ans=0;
        for(int i=1;i<=n-(n==N);i++){
            ans=max(i*solve(n-i,dp,N),ans);
        }
        dp[n]=ans;
        return ans;
    }
};
