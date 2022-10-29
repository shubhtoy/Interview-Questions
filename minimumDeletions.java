

class Solution{
    static int solve(String s,int i,int j,Integer dp[][])
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=null)
        {
            return dp[i][j];
        }
        if(s.charAt(i)==s.charAt(j))
        {
            return dp[i][j]=solve(s,i+1,j-1,dp);
        }
        return dp[i][j]=1+Math.min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    }
    static int minimumNumberOfDeletions(String s) {
        //your code here
        Integer dp[][]=new Integer[s.length()][s.length()];
        return solve(s,0,s.length()-1,dp);
    }
}
