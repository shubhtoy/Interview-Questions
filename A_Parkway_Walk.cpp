#include<bits/stdc++.h>
using namespace std;
 
int main(){
int T;
cin>>T;
while(T--){
 int n,m;
 cin>>n>>m;
 vector<int>v;
 long long int sum=0;
 for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
    sum+=x;
 }
 if(sum-m<0){
    cout<<"0"<<endl;
 }
 else{
    cout<<sum-m<<endl;
 }
 
}
return 0;
}