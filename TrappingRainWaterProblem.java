
class Solution{
    static long trappingWater(int arr[], int n) { 
        
        long waterTrapped = 0, leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        
        while(left <= right){
            
            if(arr[left] <= arr[right]){
                
                if(arr[left] > leftMax) leftMax = arr[left];
                else waterTrapped += leftMax - arr[left];
                left++;
            }
            else{
                
                if(arr[right] > rightMax) rightMax = arr[right];
                else waterTrapped += rightMax - arr[right];
                right--;
            }
        }
        return waterTrapped;
    } 
}
