// https://leetcode.com/problems/maximum-sum-circular-subarray/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res = 0, carry = 0, flag = 0, totalSum = 0;
    for (auto x : nums)
    {
        totalSum += x;
        int temp = max(carry + x, x);
        if (temp > res)
        {
            res = temp;
        }
        carry = temp < 0 ? 0 : temp;
    }
    if (res == 0)
    {
        res = nums[0];
        for (int x : nums)
            res = max(res, x);
        return res;
    }

    int minSubarraySum = INT_MAX;
    carry = 0;
    for (auto x : nums)
    {
        int temp = min(carry + x, x);
        if (temp < minSubarraySum)
        {
            minSubarraySum = temp;
        }
        carry = temp > 0 ? 0 : temp;
    }
    res = max(res, totalSum - minSubarraySum);

    return res;
    }
};
