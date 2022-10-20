#include<bits/stdc++.h>
using namespace std;

void print_subsequence(int i,vector<int>&v,int a[],int sum, int s,int n)
{
    if(i==n)
    {
        if(sum==s)
        {
            for(auto it: v)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    v.push_back(a[i]);
    s+=a[i];
    print_subsequence(i+1,v,a,sum,s,n);
    v.pop_back();
    s-=a[i];
    print_subsequence(i+1,v,a,sum,s,n);

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    vector<int>v;
    print_subsequence(0,v,a,sum,0,n);
    return 0;
}