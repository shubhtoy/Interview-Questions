 int maxLen(vector<int>&A, int n)

    {   

        // Your code here

        unordered_map<int,int> mp;

        int sum = 0,res = 0;

        mp[sum] = -1;

        for(int i = 0;i < n;i++){

            sum += A[i];

            if(mp.find(sum) != mp.end()){

                res = max(res,i - mp[sum]);

            }

            else  mp[sum] = i;

        }

       return res;

    }
