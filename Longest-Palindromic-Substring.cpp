class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int> (n,0));
        int st,len=0;
        string res;
        for(int g=0;g<s.length();g++){
            for(int i=0,j=g;j<s.length();i++,j++){
                if(g==0)
                    dp[i][j] = 1;
                else if(g==1){
                    dp[i][j] = (s[i]==s[j])?1:0;
                }
                else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]==1)?1:0;
                }
                if(dp[i][j]==1){
                    st = i;
                    len = g + 1;
                }
            }
        }
        res = s.substr(st,len);
        return res;
    }
};
