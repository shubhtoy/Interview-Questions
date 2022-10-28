class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int>result(128,0);
        for(int i=0;i<jewels.length();i++)
        {
            result[jewels[i]]++;
        }
        
        
        int answer=0;
        
        for(int i=0;i<stones.length();i++)
        {
            if(result[stones[i]]==1)
            {
            answer++;
            }
        }
        
        
        return answer;
        
    }
};
