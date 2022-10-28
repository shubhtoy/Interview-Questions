import java.util.Scanner;

public class OptimizedEcludinAlgorith {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
 		System.out.println("Enter Two numbers to find their HCF:");
		int a = sc.nextInt();
		int b= sc.nextInt();
		
		System.out.println("HCF of two number : "+ HCF(a , b));
		sc.close();

	}
   static int HCF(int a, int b) {
	   if( b== 0)
		   return a;
	   return HCF(b, a%b);
   }
}
/*
Standered Ecludien theorem;

int HCF(int a, int b) {
	while(a != b) {
		if( a > b)
			 a = a-b;
		else 
			b = b-a;
	}
	return a;
} */
