#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mod 1e9 + 7
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int>> vii;
typedef vector<pair<string, int>> vsi;

typedef stack<int> s_i;
typedef stack<string> s_s;

typedef queue<int> q_i;
typedef queue<string> q_s;

typedef priority_queue<int> p_q_max;
typedef priority_queue<int, vector<int>, greater<int>> p_q_min;

typedef unordered_set<int> u_s_i;
typedef unordered_set<string> u_s_s;

typedef unordered_map<int, int> u_m_i_i;
typedef unordered_map<string, int> u_m_s_i;
typedef unordered_map<int, string> u_m_i_s;
typedef unordered_map<int, pair<int, int>> u_m_i_i_i;

void dfsUtility(vi graph[], int source, bool status[], u_s_i& us, vector<pair<int, pair<int, int>>>& metaData, int& timestamp, u_s_i& result)
{
    metaData[source].second.first = timestamp;
    metaData[source].second.second = timestamp++;
    status[source] = 1;
    us.erase(source);
    for (auto x : graph[source])
        if (!status[x])
        {
            metaData[x].first = source;
            dfsUtility(graph, x, status, us, metaData, timestamp, result);
            if (metaData[source].second.second > metaData[x].second.second)
                metaData[source].second.second = metaData[x].second.second;
        }
        else
        {
            if (!(x == metaData[source].first))
            {
                if (metaData[source].second.second > metaData[x].second.second)
                    metaData[source].second.second = metaData[x].second.second;
            }
        }
    if (!(metaData[source].first == -1))
    {
        if (metaData[source].second.second >= metaData[metaData[source].first].second.first && metaData[metaData[source].first].first != -1)
            result.insert(metaData[source].first);
    }
}

void findArticulationPoints(vi graph[], int n, u_s_i& result)
{
    u_s_i us;
    for (int i = 0; i < n; ++i)
        us.insert(i);
    bool status[n] = { 0 };
    vector<pair<int, pair<int, int>>> metaData;
    for (int i = 0; i < n; ++i)
        metaData.push_back({ -1,{0,0} });

    int timestamp = 1;
    while (!us.empty())
        dfsUtility(graph, *us.begin(), status, us, metaData, timestamp, result);

    vi rootNodes;
    for (int i = 0; i < n; ++i)
    {
        if (metaData[i].first == -1)
            rootNodes.push_back(i);
    }
    for (auto root : rootNodes)
    {
        int childOfRoot = 0;
        for (auto x : metaData)
            if (x.first == root)
                childOfRoot++;
        if (childOfRoot > 1)
            result.insert(root);
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
        graph[um[b]].push_back(um[a]);
    }

    // for (int j = 0; j < n; ++j)
    // {
    //     cout << endl << alpha[j] << ": ";
    //     for (auto x : graph[j])
    //         cout << alpha[x] << " ";
    // }

    u_s_i result;
    findArticulationPoints(graph, n, result);
    cout << "No of articulation points: " << result.size() << "\nArticulation Points: ";
    for (auto x : result)
        cout << alpha[x] << " ";
    return 0;
}
