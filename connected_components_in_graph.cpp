#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
void dfs(int vertex)
{
vis[vertex]=1;
for(auto child:g[vertex])
{
    if(vis[child])
    continue;
    dfs(child);

}

}
int main(int argc, char const *argv[])
{

int n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int v1,v2;
    cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);

}
int c=0;
for(int i=1;i<=n;i++)
{
    if(vis[i]==0)
    {
        dfs(i);
        c++;

    }
}
cout<<c<<endl;

    return 0;
}
