import java.util.Scanner;

public class checkpalidrome {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
  
		 Scanner sc = new Scanner(System.in);
		 System.out.println("enter no to check palidrome :");
		 int num = sc.nextInt();
		 
		 System.out.println("Is number Palidrome :"+ ispalidrome(num));
		 sc.close();
	}
	
	static boolean ispalidrome(int n) {
		if( n <0 )
			return false;
		if( n >= 0 && n <= 9)
			return true;
		//int temp;
		int rev= 0;                   // int temp = n
		while (n > rev) {             // int rev = 0
			int ld = n%10;            // while( temp != 0) 
			rev = rev*10 + ld;        //   int ld = n %10
			n = n/10;                 // rev = rev *10 + ld
		}                              // temp = temp/10
		return (n == rev);              // return (rev == n)
	}

} 
