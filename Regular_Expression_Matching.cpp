class Solution {
public:
    
    bool fun(string s,string p,int i,int j){
        if(i==-1 && j==-1) return true;
        if(i!=-1 && j==-1) return false;
        if(i==-1 && j!=-1){
            if(p[j]=='*') return fun(s,p,i,j-2);
            else{
                return false;
            }
        }
        else{
            if(s[i]==p[j] || p[j]=='.') return fun(s,p,i-1,j-1);
            else if(p[j]=='*'){
                if(s[i]==p[j-1] || p[j-1]=='.') return fun(s,p,i-1,j) || fun(s,p,i,j-2);
                else{
                    return fun(s,p,i,j-2);
                }
            }
            else{
                return false;
            }
        }
    }
    
    bool isMatch(string s, string p) {
        return fun(s,p,s.size()-1,p.size()-1);
        
    }
};
