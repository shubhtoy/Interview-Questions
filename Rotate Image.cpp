class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        
        int n=a.size();
        for(int i=0;i<n;i++)
            for(int j=i;j<n-i-1;j++){
                int prev1=a[n-j-1][i];
                swap(a[i][j],prev1);
                swap(a[j][n-i-1],prev1);
                swap(a[n-i-1][n-j-1],prev1);
                swap(a[n-j-1][i],prev1);
          }
        
    }
};
