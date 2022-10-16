#include <bits/stdc++.h>
#define int long long 
using namespace std;
class Graph
{
    int V;
    list<int> *l;
    public:
            Graph(int v)
            {
                V=v;
                l=new list<int>[V];

            }
            void addEdge(int i,int j,bool undir=true)
            {
                if(undir)
                {
                    l[i].push_back(j);
                    l[j].push_back(i);

                }
            }
            void printAdjList()
            {
                for(int i=0;i<V;i++)
                {
                    cout<<i<<"----->";
                    for(auto node:l[i])
                    {
                        cout<<node<<",";
                    }
                    cout<<endl;

                }
                
            }
            void bfs(int source)
            {
                queue<int> q;
                bool vis[V]={0};
                q.push(source);
                vis[source]=true;
                while(!q.empty())
                {
                    int f=q.front();
                    cout<<f<<" ";
                    q.pop();
                    //push the neighbours of the current node if it is not visited 
                   for(auto nbrs:l[f])
                   {
                       if(!vis[nbrs])
                       {
                        q.push(nbrs);
                        vis[nbrs]=true;

                       }

                   }

                }

            }
            void dfs_helper(int source ,bool vis[])
            {
                cout<<source<<" ";
                vis[source]=true;
                for(auto val:l[source])
                {
                    if(!vis[val])
                    dfs_helper(val,vis);

                }
                return ;
                
            }
            void dfs(int source)
            {
                bool vis[V]={0};
                dfs_helper(source,vis);

            }

};
int32_t main()
{

Graph g(7);

g.addEdge(0,1);
g.addEdge(2,1);
g.addEdge(2,3);
g.addEdge(3,5);
g.addEdge(5,6);
g.addEdge(3,4);
g.addEdge(0,4);
cout<<"BFS : ";
g.bfs(1);
cout<<endl;
cout<<"DFS : ";
g.dfs(1);





    return 0;
}
