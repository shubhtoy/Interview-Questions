public class L18_MathforDSA {
    public static void main(String[] args) {
        //Telling  Prime numbers upto n numbers
        // Most optimal solution with time comlexicity of square root n
        int n1 =8;
        for (int i=1;i<=n1;i++){
            System.out.println("The number "+ i +" is prime ="+ IsPrime(i));
        }

        // Printing all prime number less than n
        int n2 = 40;
        System.out.println();
        System.out.println("All prime numbers less than "+ n2 +"are -");
        for (int i=1;i<=n2;i++){
            if(IsPrime(i)==true){
                System.out.println(i);
            }

        }
        // But above has time complexicity of n*squarerootof n or n ki power 3/2 , but we can still optimize it





    }
    static boolean IsPrime(int m){
        if(m<=1){
            return false;
        }

        for(int i=2;i<=Math.sqrt(m);i++){
            if(m%i==0){
                return false;
            }
        }
        return true;
    }
}
