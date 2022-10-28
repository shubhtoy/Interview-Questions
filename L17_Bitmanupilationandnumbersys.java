public class L17_Bitmanupilationandnumbersys {
    public static void main(String[] args) {
   //Q1 Finding even and odd
        int num=5;
        System.out.println(isodd(num));
        //Q2 Finding unique element in array Or element not having its pair
        int[] arr={1,2,1,2,44,5,5,6,6,44,8};
        // Using the property the XOR operator is accociative and a^a =0(or even times of XOR product of a ) and a^0=a. Hence by doing XOR product of all elements of array we will get unique element
        System.out.println(Unique(arr));

        //Q4 Finding ith bit of a number

        // Find nth magic number
        int n=6;
        System.out.println(Magicnum(n));
        // Find number of digits in base b
        int n5=10;
        int b=2;
        System.out.println(Noofdigit(n5,b));

        //Find out if a numberis power of 2 or not
        int numb= 32;
        // n=0 is an exception
        if(n==0){
            System.out.println("false");
        }
        if((numb & numb-1)==0){
            System.out.println("yes");
        }
        else
            System.out.println("no");

        // Find a ki power b



        //For a given no find no of set bits
        // Method 1
         n= 9;
        int count=0;
        while (n>0){
            if((n&1)==1){
            count++;}
            n=n>>1;
        }
        System.out.println(count);
        // Method 2
        n=7;
        System.out.println(Setbits(n));

        // Find XOR of no from 0 to a








    }
    static boolean isodd(int n){
        //Using bit manipulation and properties of "and" operator
        if((n&1)==1){
            return true;
        }
        else {
            return false;
        }

    }
    static int Unique(int arr[]){
        int XORproduct=arr[0];
        for (int i=1;i< arr.length;i++){
            XORproduct ^= arr[i];
        }
        return XORproduct;
    }
    static int Magicnum(int n){
        int base=5;
        int reqnum=0;
        while(n>0){
            int last = n&1;
            n=n>>1;
             reqnum += base*last;
             base = base*5;

        }
        return reqnum;

    }
    static int Noofdigit(int n,int base){
        int ans= (int)(Math.log(n)/Math.log(base)) +1;
        return ans;


    }
    static int Setbits(int n){
        int count=0;
        while (n>0){
            n-=n&-n; // n&-n is way of finding rightmost bit . We are subtracting it from n after each iteration to remove that rightmost bit and then finding other bit .
            count++;
            //OR
            // n=n&n-1;//This will give us n without rigtmost set bit
            // count++;


        }
        return count;
    }



}
