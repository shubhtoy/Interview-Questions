int dp[305][15];
    int helper(vector<int>& arr, int i, int n, int d)
    {
       
        if(i == n && d == 0) return 0;
        
        if(d <= 0) return INT_MAX;
        
        if(dp[i][d] != -1) return dp[i][d];
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int j = i; j < n; j++)
        {
            maxi = max(maxi, arr[j]);
            int temp = helper(arr, j + 1, n, d - 1);    
            if(temp != INT_MAX)
            {
                mini = min(mini, maxi + temp);
            }
        }
        
        return dp[i][d] = mini;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        memset(dp,-1,sizeof(dp));
        return helper(jobDifficulty,0,n,d);
    }
