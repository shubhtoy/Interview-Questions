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

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);

    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=1)
        {
                dfs(i);
                c++;

        }
    }
    cout<<c<<endl;
    

}
