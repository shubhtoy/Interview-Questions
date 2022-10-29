bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0,n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum%k==0 && i>0) return true;
            
            if(m.count(sum%k) && (i-m[sum%k]>=2)) return true; //if same remainder come again from that remainder to this there must be sum of conti subarray which is multiple of k
            
            if(!m.count(sum%k)) m[sum%k]=i;
        }
        return false;
    }
