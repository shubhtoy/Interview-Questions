#include <bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

class Solution
{
    public:
    
    int solve(int x, int y, string s1, string s2, vector<vector<int>> &dp){
        
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(x==0 || y==0) dp[x][y] = 0;
        else{
            if(s1[x-1]==s2[y-1]) dp[x][y] = 1 + solve(x-1, y-1, s1, s2, dp);
            else dp[x][y] = max(solve(x-1, y, s1, s2, dp) , solve(x, y-1, s1, s2, dp));    
        }
        
        return dp[x][y];
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector <int>> dp(x+1, vector<int>(y+1, -1));
        return solve(x, y, s1, s2, dp);
    }
};

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
