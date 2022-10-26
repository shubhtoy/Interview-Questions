#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define endl "\n"
#define mod 1e9 + 7
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

void make_set(vi &parent)
{
    parent.push_back(-1);
}
int find(vi &parent, int node) //Iterative find() with path compression
{
    int representative;
    while (1)
    {
        if (parent[node] < 0)
        {
            representative = node;
            break;
        }
        node = parent[node];
    }
    while (1)
    {
        if (parent[node] < 0)
            break;
        int temp = node;
        node = parent[node];
        parent[temp] = representative;
    }
    return representative;
}

int find_rec(vi &parent, int node) //Recursive find() with path compression
{
    if (parent[node] < 0)
        return node;
    else
        parent[node] = find_rec(parent, parent[node]);
    return parent[node];
}

void __union(vi &parent, int x, int y) //Optimized Union Function (Union by Rank)
{
    x = find_rec(parent, x);
    y = find_rec(parent, y);
    if (x == y)
        return;
    if (parent[x] < parent[y])
        parent[y] = x;
    else if (parent[x] == parent[y])
        parent[y] = x, parent[x]--;
    else
        parent[x] = y;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> alpha;
    unordered_map<string, int> um;
    vi parent;
    int n;
    cin >> n;
    string temp;
    int i = n;
    while (i--)
    {
        cin >> temp;
        alpha.push_back(temp);
        um[temp] = alpha.size() - 1;
        make_set(parent);
    }
    cin >> i;
    string a, b;
    while (i--)
    {
        cin >> a >> b;
        __union(parent, um[a], um[b]);
    }
    for (i = 0; i < n; ++i)
        if (parent[i] < 0)
            cout << alpha[i] << "  ";
    return 0;
}
