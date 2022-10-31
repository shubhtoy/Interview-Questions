class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
       vector<int> ans;
       for(int i=0;i<nums.size();i++){
           //Remove out of range k
           if(!dq.empty() && dq.front() == i-k) dq.pop_front();
           
           //remive smaller numbers in k range as they are useless
           while(!dq.empty() && nums[dq.back()] <= nums[i]){
               dq.pop_back();
           }
           
           dq.push_back(i);
           if(i >= k-1){
               ans.push_back(nums[dq.front()]);
           }
       }
       return ans;
    }
};
