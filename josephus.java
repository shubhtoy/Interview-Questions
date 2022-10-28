public class josephus {
    public static void main(String[] args){
        int n = 5, k = 3;
        
        System.out.println("n start with 0 ->"+jos(n, k));// n start with 0,1......n
        System.out.println("n start with 1 ->"+n_start_one(n, k));// n start with 1......n

    }
    static int jos(int n, int k){
        if(n==1) return 0; // n start with 0,1......n
       return (jos(n-1,k)+k)%n;
    }
    static int n_start_one(int n, int k){
        return jos(n,k)+1;// n start with 1......n by adding 1 in joseph result.
    }
}
