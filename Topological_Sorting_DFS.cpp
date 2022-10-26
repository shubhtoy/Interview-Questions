#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define endl "\n"
#define mod 1e9 + 7
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

struct node
{
    string str;
    int x;
    int y;
    int parent;
};

void print_node(node temp)
{
    cout << temp.str << ", d = " << temp.x << ", f = " << temp.y << "";
}
void topological_sort_dfs(vector<int> graph[], int source, unordered_set<int>& us, stack<int>& s, int status[])
{
    status[source] = 1;
    us.erase(source);
    for (auto x : graph[source])
        if (status[x] == 0)
            topological_sort_dfs(graph, x, us, s, status);
        else if (status[x] == 1)
            cout << "Cyclic Graph!!!!!!!\n";
    s.push(source);
    status[source] = 2;
}

void topological_sort(vector<int> graph[], vector<string> alpha)
{
    unordered_set<int> us;
    stack<int> s;
    int status[alpha.size()] = { 0 };
    for (int i = 0; i < alpha.size(); ++i)
        us.insert(i);
    while (!us.empty())
        topological_sort_dfs(graph, *us.begin(), us, s, status);
    while (!s.empty())
    {
        cout << alpha[s.top()] << " ";
        s.pop();
    }
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
