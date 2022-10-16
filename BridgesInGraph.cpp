#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timer=1;
    int u , v;
    int flag=false;
    void dfs(int node , int par , vector<int>&in , vector<int>&low , vector<int>&vis , vector<int> G[]){
        vis[node]=1;
        in[node]=low[node]=timer++;
        for(auto i : G[node]){
            if(i==par) continue;
            else if(vis[i]) low[node]=min(low[node] , in[i]);
            else{
                dfs(i , node , in , low , vis , G);
                low[node]=min(low[node] , low[i]);
                if(low[i]>in[node]){
                    if((node==u and i==v) || (node==v and i==u)){
                        flag=true;
                        return ;
                    }
                }
            }
        }
    }
    
    bool isBridge(int V, vector<int> adj[], int c, int d)  {
        u=c , v=d;
        vector<int> in(V , 0) , low(V , 0) , vis(V , 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i , -1 , in , low , vis , adj);
                if(flag) return true;
            }
        }
        return false;
    }
};

int main() {
	int V, E;
	cin >> V >> E;
	vector<int> adj[V];
	int i=0;
	while (i++<E) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back (v);
		adj[v].push_back (u);
	}
	int c,d;
	cin>>c>>d;
	Solution obj;
	cout<<obj.isBridge(V, adj, c, d)<<'\n';
    return 0;
}
