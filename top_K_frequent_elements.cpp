class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        priority_queue<pair<int,int>>pq;
        for(auto & val:m)
        {
            pq.push({val.second,val.first});
            
        }
        vector<int> v;
        while(k--)
        {
            auto x= pq.top();
            
            v.push_back(x.second);
            pq.pop();
            
        }
        return v;
        
        
    }
};
