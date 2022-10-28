public class dp_max_sum_inc_subs {

        public static void main(String args[]) {
    
            int arr[] = {12,13,15,10,9,18};
            dp_max_sum_inc_subs b = new dp_max_sum_inc_subs();
            System.out.println(b.msis(arr,arr.length));
        }
         int msis(int[] arr,int n){
                int msis[] = new int[n];
                for(int i =0; i<n;i++){
                    msis[i] =arr[i];
                    for(int j =0;j<i;j++){
                        if(arr[j]<arr[i])
                            msis[i] = Math.max(msis[i],msis[j]+arr[i]);
                        }
                    }
                int res = msis[0];
                for(int i =1; i<n;i++){
                    res = Math.max(res,msis[i]);
                }
                return res;
            }
        }
