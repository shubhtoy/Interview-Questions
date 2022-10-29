class Solution {
    public int subarrayGCD(int[] nums, int k) {
        if(nums.length == 1) {
            if(nums[0] == k) return 1;
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < nums.length; i++) {
             int pro = nums[i];
            if(nums[i] == k) ans++;
            for(int j = i + 1; j < nums.length; j++) {
                int res = gcd(pro, nums[j]);
                if(res == k) ans++;
                pro *= nums[j];
            }
        }
        return ans;
    }
    int gcd(int a, int b) {
        if (a == 0)
          return b;
        if (b == 0)
          return a;
        if (a == b)
            return a;
      
        // a is greater
        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }
}
