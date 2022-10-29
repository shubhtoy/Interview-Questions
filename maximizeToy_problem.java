

class Solution{
    static int toyCount(int N, int K, int arr[])
    {
        int count = 0;
        int sum = 0;
        Arrays.sort(arr);
        for(int i = 0; i < N; i++){
            if(arr[i] + sum <= K){
                sum = sum + arr[i];
                count++;
            }
        }
        return count;
    }
}
