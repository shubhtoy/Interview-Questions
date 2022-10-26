class Solution {
public:
    vector<string> letterCombinations(string &digits) {
        
          vector<string> ans;
        unordered_map<char,vector<char>> mp;
        string temp;
        char c='a';
           for(char i='2';i<='9';i++){
               if(i=='7' || i=='9'){
                for(int j=0;j<4;j++){
                    mp[i].push_back(c);
                    c++;
                }
               }
               else{
                   for(int j=0;j<3;j++){
                    mp[i].push_back(c);
                    c++;
                }
               }
           }
            all(digits,mp,temp,0,ans);
        return ans;
    }
    void all(string &digits, unordered_map<char,vector<char>> &mp,string &temp,int st, vector<string> &ans){
        
        
        if(st==digits.length()){
            if(temp.length()!=0)
            ans.push_back(temp);
            return;
        }
        for(auto x:mp[digits[st]]){
            temp.push_back(x);
            all(digits,mp,temp,st+1,ans);
            temp.pop_back();
        }
    }
};
