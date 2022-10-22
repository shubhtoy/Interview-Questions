class Solution {
public:
    int minDistance(string &a, string &b) {
            int n=a.length();
            int m=b.length();
        vector<int> pre(m + 1, 0), curr(m + 1, 0);
        for(int i=0;i<=m;i++){
            pre[i]=i;
        }
        for(int i=1;i<=n;i++){
            curr[0]=i;
        for(int j=1;j<=m;j++){
             curr[j]=pre[j-1];        
            if(a[i-1]!=b[j-1])
                curr[j]=1+min({pre[j],  //delete
                               curr[j], //replace
                               curr[j-1]} //insertion
                             ); 
        }
            pre=curr;
    }
            
        return pre[m];
    }
   
};
