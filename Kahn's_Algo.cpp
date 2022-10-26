// Kahn's Algorithm
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define endl "\n"
#define mod 1e9 + 7
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

void topological_sort_bfs(vector<int> graph[], vector<string> alpha, int dependencies[], queue<int> &q)
{
    while (!q.empty())
    {
        cout << alpha[q.front()] << " ";
        for (auto x : graph[q.front()])
        {
            dependencies[x]--;
            if (dependencies[x] == 0)
                q.push(x);
        }
        q.pop();
    }
}

void topological_sort(vector<int> graph[], vector<string> alpha)
{
    queue<int> q;
    int dependencies[alpha.size()] = {0};
    for (int i = 0; i < alpha.size(); ++i)
        for (auto x : graph[i])
            dependencies[x]++;

    for (int i = 0; i < alpha.size(); ++i)
        if (dependencies[i] == 0)
            q.push(i);
    topological_sort_bfs(graph, alpha, dependencies, q);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n; //Number of vertices
    i = n;
    string temp;
    vector<string> alpha;
    unordered_map<string, int> um;
    while (i--)
    {
        cin >> temp;
        alpha.push_back(temp);
        um.insert(make_pair(temp, alpha.size() - 1));
    }

    vector<int> graph[n];
    string a, b;
    cin >> i;
    while (i--)
    {
        cin >> a >> b;
        graph[um[a]].push_back(um[b]);
    }

    topological_sort(graph, alpha);

    return 0;
}
