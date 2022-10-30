#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ve vector<int>
#define vell vector<ll>
#define vpp vector<pair<int, int>>
#define ump unordered_map<int, int>
#define rep1(i, a, b) for (int i = a; i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, n) for (int i = (n)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define asort(a) sort(a, a + n)
#define all(x) (x).begin(), (x).end()
#define uniq(v) v.erase(unique(all(v)), (v).end())
#define vmax(v) *max_element(v.begin(), v.end());
#define vmin(v) *min_element(v.begin(), v.end());
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7; // 998244353;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> sum(m, vector<int>(n, grid[0][0]));
    for (int i = 1; i < m; i++)
        sum[i][0] = sum[i - 1][0] + grid[i][0];
    for (int j = 1; j < n; j++)
        sum[0][j] = sum[0][j - 1] + grid[0][j];
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
    return sum[m - 1][n - 1];
}
void solve()
{
    vector<vector<int>> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            v1.push_back(a);
        }
        v.push_back(v1);
    }
    ll ans= minPathSum(v);
    cout<<ans<<endl;
}
int main()
{

    (ios_base::sync_with_stdio(false), cin.tie(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
