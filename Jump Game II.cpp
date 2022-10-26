class Solution {
public:
    int jump(vector<int>& nums) {
        
       int n=nums.size();
        vector<int> dp(n+1,INT32_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){

            for(int j=min(n-1,i+nums[i]);j>i;j--){
                
                if(dp[j]==INT32_MAX)
                    continue;
                else{
                    dp[i]=min(1+dp[j],dp[i]);
                   }
            }
        }
        return dp[0];
    }
};
