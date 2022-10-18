class Solution {
public:
    int dp[1005][1005];
    
    int lc(int x,int y,string &s,string &t)
    {
            if(x<0 || y<0)
                return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(s[x]==t[y])
        {
            return dp[x][y]=1+lc(x-1,y-1,s,t);
        }
        
            return dp[x][y]=max(lc(x-1,y,s,t),lc(x,y-1,s,t));
        
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lc(text1.size()-1,text2.size()-1,text1,text2);
        
        
    }
};
