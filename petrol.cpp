#include<iostream>
#include<vector>
using namespace std;
int main(){
cout<<"Enter the total number of petrol pumps"<<endl;
int n;cin>>n;
int A[n];
cout<<"Enter the distances of each petrol pump from Bongora"<<endl;
for(int i=0;i<n;i++){
    cin>>A[i];
}
cout<<"Enter the value of mileage: "<<endl;
int c;cin>>c;
int cfuel=0;//nitialy filled the petrol at Bongora
int res[n];
int idx=0;
for(int i=1;i<n;i++){
if(cfuel<(A[i]-A[i-1])){
    res[idx]=A[i];
    idx++;
    
    cfuel=c;

    if(cfuel<A[i]-A[i-1]){
        cout<<"Cannnot reach destination"; return 0;
    }}
cfuel=cfuel-(A[i]-A[i-1]);

}
cout<<"Result:"<<endl;
for(int i=0;i<idx;i++){
    cout<<res[i]<<" ";

}
 }

