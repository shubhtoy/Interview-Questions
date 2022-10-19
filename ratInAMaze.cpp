#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector <string> ans;
    void findPathRec(vector<vector<int>> &m, int n, string curr, int i, int j){
        if(i<0 || j<0 || j>=n || i>=n || m[i][j]==0) return;
        
        if(i==n-1 && j==n-1){
            ans.push_back(curr);
            return;
        }
        
        m[i][j]=0;
        
        findPathRec(m, n, curr+'D', i+1, j);
        findPathRec(m, n, curr+'R', i, j+1);
        findPathRec(m, n, curr+'U', i-1, j);
        findPathRec(m, n, curr+'L', i, j-1);
        
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ans.clear();
        string curr= "";
        findPathRec(m, n, curr, 0, 0);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}