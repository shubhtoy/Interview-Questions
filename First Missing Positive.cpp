class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]<=0 || nums[i]>n || nums[nums[i]-1]==nums[i]);
            else 
            swap(nums[i],nums[nums[i]-1]),i--;
            

        int i=0;
        while(i<n && nums[i]==i+1){
            i++;
        }
        return i+1;
    }
};
