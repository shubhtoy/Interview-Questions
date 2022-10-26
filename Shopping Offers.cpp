class Solution {
public:
    map<vector<int>,int> mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        if(mp[needs])
        return mp[needs];
        int ans=cost(price,needs);
        for(int i=0;i<special.size();i++){
            int flag=1;
            for(int j=0;j<needs.size() && flag;j++)
                if(needs[j]<special[i][j])
                flag=0;
            
            if(flag){
                int n=needs.size();

                for(int j=0;j<needs.size();j++)
                    needs[j]-=special[i][j];

                ans=min(ans,special[i][n]+shoppingOffers(price,special,needs));

                for(int j=0;j<needs.size();j++)
                    needs[j]+=special[i][j];
            }
        }
        mp[needs]=ans;
        return mp[needs];
    }
     int cost(vector<int>& price,vector<int>& needs ){
        int c = 0;
        for(int i = 0;i<price.size();i++) c+=price[i]*needs[i];
        return c;
    }
};
