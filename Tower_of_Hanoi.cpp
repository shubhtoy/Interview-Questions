#include <bits/stdc++.h>
#define int long long 
using namespace std;
void toh(int n,char from,char aux,char to)
{
    if(n==0)
    return ;
    toh(n-1,from,to,aux);
    cout<<from<<"-->"<<to<<endl;
    toh(n-1,aux,from,to);

}
int32_t main()
{

cout<<"Enter the number of disks : "<<endl;
int n;
cin>>n;
toh(n,'A','B','C');

    return 0;
}
