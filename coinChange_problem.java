

class Solution {
    public long count(int coins[], int N, int sum) {
        // code here.
        
         long K[][] = new long[N+1][sum+1];
      
        
        for(int i =0;i<=N;i++){
            for(int j =0;j<=sum;j++){
               if(i==0){
                   K[i][j]=0;
               }  
               if(j==0){
                   K[i][j]= 1;
               }
              
            }
        }
        for(int i =1;i<=N;i++){
            for(int j = 1;j<=sum;j++){
                
                if(coins[i-1]<=j){
                    K[i][j] = K[i][j-coins[i-1]]+K[i-1][j];
                }
                else{
                    K[i][j] = K[i-1][j];
                }
            }
        }
        return K[N][sum];
        
        
        
    }
}
