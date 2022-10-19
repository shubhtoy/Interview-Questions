#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void bfs(int source, vector <int> graph[250010], bool vis[250010], int level[250010]){
        queue<int> q;
        q.push(source);
        vis[source]=true;
        
        while(!q.empty()){
            int cur_ver = q.front();
            q.pop();
            for(auto child : graph[cur_ver]){
                if(!vis[child]){
                    q.push(child);
                    vis[child]=true;
                    level[child]=level[cur_ver]+1;
                }
                
            }
        }
    }
    
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        int g[n+2][m+2];
        // 1 based indexed -> add 1 to source and destination coordinates
        for(int i=0;i<n+2;i++){
            for(int j=0;j<m+2;j++){
                g[i][j]=0;
                if((i>=1 && i<=n) && (j>=1 && j<=m))
                g[i][j]=grid[i-1][j-1];
            }
        }
        
        int N = 250010;
        vector <int> graph[N];
        bool vis[N];
        int level[N];
        for(int i=0;i<N;i++){
            vis[i]=false;
            level[i]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(g[i][j]==1){
                    if(g[i][j+1]==1){
                        graph[(i-1)*m+j].push_back((i-1)*m+j+1);
                    }
                    if(g[i+1][j]==1){
                        graph[(i-1)*m+j].push_back((i)*m+j);
                    }
                    if(g[i][j-1]==1){
                        graph[(i-1)*m+j].push_back((i-1)*m+j-1);
                    }
                    if(g[i-1][j]==1){
                        graph[(i-1)*m+j].push_back((i-2)*m+j);
                    }
                }
            }
        }
        
        source.first++;
        source.second++;
        destination.first++;
        destination.second++;
        
        int s=(source.first-1)*m+source.second;
        bfs(s, graph, vis, level);
        
        int d=(destination.first-1)*m+destination.second;
        
        if(s==d)
        return 0;
        else if(level[d]==0)
        return -1;
        else
        return level[d];
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}