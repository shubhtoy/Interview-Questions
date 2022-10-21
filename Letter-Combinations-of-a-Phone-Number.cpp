class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        vector<string> map{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty())
            return {};
        v.push_back("");
        for(auto it:digits){
            vector<string> tmp;
            for(auto it1:map[it-'2']){
                for(auto it2:v){
                    tmp.push_back(it2+it1);
                }
            }
            v.swap(tmp);
        }
        return v;
    }
};
