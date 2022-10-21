class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int h,maxi=0;
        while(i<j){
            h = min(height[i],height[j]);
            maxi = max(maxi,h*(j-i));
            while(i<j && height[i]<=h)
                ++i;
            while(i<j && height[j]<=h)
                --j;
        }
        return maxi;
    }
};
