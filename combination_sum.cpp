#include<bits/stdc++.h>
using namespace std;

void findcombinationsum(int i,int target,vector<int>&a,vector<vector<int>>&ans,vector<int>&ds)
{
    if(i==a.size())
    {
        if(target==0)
        {
            ans.push_back(ds);
        }
        return;
    }
    //pick element

    if(a[i]<=target)
    {
        ds.push_back(a[i]);
        findcombinationsum(i,target-a[i],a,ans,ds);
        ds.pop_back();
    } 

    findcombinationsum(i+1,target,a,ans,ds);

}

vector<vector<int>> combinationsum(vector<int>&c,int target)
{
    vector<vector<int>>ans;
    vector<int>ds;
    findcombinationsum(0,target,c,ans,ds);
    return ans;
}

int main(){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        vector<vector<int>> result = combinationsum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
}