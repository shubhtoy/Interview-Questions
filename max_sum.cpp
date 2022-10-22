class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        int sum=0;
       // int ans=0;
        int n=nums.size();
        if(firstLen>secondLen)
        swap(firstLen,secondLen);
        vector<int> pre(n+1,0);
        vector<int> suff(n+1,0);
        int st=0;
        pre[0]=nums[0];
        sum=nums[0];
        for(int i=1;i<n;i++){
            if(i-st+1>firstLen){
                sum-=nums[st];
                st++;
            }
            sum+=nums[i];
            pre[i]=max(pre[i-1],sum);
        }
        sum=nums[n-1];
        suff[n-1]=nums[n-1];
        st=n-1;
        for(int i=n-2;i>=0;i--){
            if(st-i+1>firstLen){
                sum-=nums[st];
                st--;
            }
            sum+=nums[i];
            suff[i]=max(suff[i+1],sum);
        }
        st=0;
        sum=pre[firstLen-1];
        int curr=0;
        for(int i=firstLen;i<n;i++){
            
            if(i-st+1>secondLen){
                sum-=nums[st];
                st++;
            }
            sum+=nums[i];
            curr=max(curr,max(st>=1?pre[st-1]:0,i<n-1?suff[i+1]:0)+sum);
       }
       return curr;
    }
};
