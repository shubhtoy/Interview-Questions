int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int sum=0,maxi=-1,n=plantTime.size();
        
        vector<pair<int,int>> p(n);
        
        for(int i=0;i<n;i++){
            p[i]={growTime[i],plantTime[i]};
        }
        sort(p.begin(),p.end(),greater<pair<int, int>>());
        
        for(int i=0;i<n;i++){
            sum+=p[i].second;
            maxi=max(sum+p[i].first,maxi);
        }
        
        return maxi;
    }
