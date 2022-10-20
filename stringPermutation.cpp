#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	    set<string> v;
	    void solve(string S, int i){
	        if(i== S.length()-1){
	            v.insert(S);
	            return;
	        }
	        for(int j=i; j<S.length(); j++){
		        swap(S[j], S[i]);
		        solve(S, i+1);
		        swap(S[j], S[i]);
		    }
	    }
		vector<string>find_permutation(string S)
		{
		    solve(S, 0);
		    vector<string> vec(v.begin(), v.end());
		    return vec;
		    
		}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
