#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int n;
    int r;
    int k=0;
    int sum=0;
    cin>>n;

    while(n!=0)
    {
       r=n%10;
       sum=sum+(r*pow(8,k++));
       n=n/10;

    }
    cout<<sum;
    return 0;
}