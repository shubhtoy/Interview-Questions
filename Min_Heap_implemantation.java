
public class Min_Heap_Implementation {
    public static void main(String[] args){

        int[] arr = {4, 2,6,5,1,8,9};
        int n = arr.length;

        int startIndex = n/2-1;

        for( int i= startIndex ; i >= 0 ; i--){
            Heapify( arr, i, n);
        }

        for( int x : arr){
            System.out.print( x + " ");
        }
    }

    public static void Heapify( int[] arr , int i, int n){
        
        int smallest = i;

        int l = 2*i+1;
        int r = 2* i+2;

        if( l < n && arr[l] < arr[i]){
            smallest = l;
        }

        if( r < n && arr[r] < arr[i])
          smallest = r;
        
        if( smallest != i){
            // swap smallest value with arr[i]//
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;

            //call Heapify for distrubed subtree//
            Heapify(arr, smallest, n);
        }
    }
}
