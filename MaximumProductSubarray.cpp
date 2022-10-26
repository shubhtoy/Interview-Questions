// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:

int maxProduct(vector<int>& nums)
{
    int n = nums.size();

    int currMax = 1, currMin = 1, res = INT_MIN;
    for (auto x : nums)
        if (x > res)
            res = x;

    for (auto x : nums)
    {
        if (!x)
        {
            currMax = 1;
            currMin = 1;
        }
        else
        {
            int temp = currMax * x;
            currMax = max(temp, max(currMin * x, x));
            currMin = min(temp, min(currMin * x, x));
            res = max(res, max(currMax, currMin));
        }
    }
    return res;
}
};
