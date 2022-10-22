class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int sum=0;
        int ans=0;
        int st=0;
        for(int i=0;i<nums.size();i++){
            
            while(st<i && mp[nums[i]]){
                mp[nums[st]]=false;
                 sum-=nums[st];
                st++;
               
            }
            sum+=nums[i];
            mp[nums[i]]=true;
            ans=max(sum,ans);
        }
        return ans;
    }
};
