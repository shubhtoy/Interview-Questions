#include<bits/stdc++.h>
using namespace std;
 
int main(){
int T;
cin>>T;
while(T--){
 int n,m;
 cin>>n>>m;
 string s;
 cin>>s;
 string a;
 cin>>a;
 string s1=s;
 s1.erase(remove(s.begin(),s.end(),'?'));
 if(s1==a){
     cout<<"-1"<<endl;
 }
 int flag=0;
 char temp;
 for(int i=0;i<n;i++){
     if(s[i]=='?'){
         if(flag==1){
             cout<<temp;
         }
         continue;
     }
     else{
         flag=1;
         temp=s[i];
     }
 }
 cout<<endl;
 
}
return 0;
}