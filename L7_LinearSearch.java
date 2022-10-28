import java.util.Scanner;
import java.util.Arrays;

public class L7_LinearSearch {
    public static void main(String[] args) {
        //Basic linear search
        int[] num = {1,2,3,-1,4,5};
        int element= 5;
        System.out.println(linearSearch(num,element));

        //Q2  For String
   String st = "Anlit";
   char target = 'l';
        System.out.println(Q2searchinStrings(st,target));

        //Q3 Minimum in array
        System.out.println(Q3MinnuminArray(num));
        //Q4 Search in 2d array
        int[][] arr2d= {
                {1, 2, 3},
                {4, 5, 6},
                {6,8,90,5}
        };
        int req=90;
        int[] ans= Q4searchin2d(arr2d,req);// See format of return value {row, col}
        System.out.println(Arrays.toString(ans));
        //max element in 2d aray
        System.out.println(Q5Maxvaluein2Darray(arr2d));

        //leeetcode Q and its solution
        //https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
        int[] nums ={133,34,4567,12,1,56};
        System.out.println(Q6noofeven(nums));
        // Check vedio for optimized solution

        //Q6 https://leetcode.com/problems/richest-customer-wealth/
        //check solution on leetcode




    }
    static int linearSearch(int[]arr , int element){
        if(arr.length==0){
            return -1;
        }
        for(int i=0;i< arr.length;i++)
        {
            if(arr[i]==element)
            {
                return i;
            }
        }
//This will execute if no statement will execute

        return -1;

    }
    static int Q2searchinStrings(String str , char target){
        // Here we used length() not length as for strings we have length() function
        if(str.length()==0){
            return -1;

        }
        for(int j=0;j<str.length();j++)
            if(target==str.charAt(j)){
                return j;
            }
return -1;
    }
    static int Q3MinnuminArray(int[]arr){
        int min= arr[0];
        for(int i=0;i<arr.length;i++){
            if(min >arr[i]){
                min=arr[i];
            }
        }
        return min;
    }
    static int[] Q4searchin2d(int[][]arr,int required){
        for (int row =0;row<arr.length;row++){
            for (int col=0;col<arr[row].length;col++){
                if (required==arr[row][col]){
                    return new int[]{row, col};//This is the format to return row and col
                }
            }
        }
        return new int[]{-1, -1};

    }
    static int Q5Maxvaluein2Darray(int[][]arr){
        int max=arr[0][0];
        for (int[] ints : arr) {
            for (int col = 0; col < ints.length; col++) {
                if (ints[col] > max) {
                    max = ints[col];
                }
            }
        }
        return max;

    }
    static int Q6noofeven(int[]arr){
        int count = 0;
        //Enhanced for loop
        for (int i = 0; i < arr.length; i++) {
            int j = arr[i];
            if (count(j) % 2 == 0) {
                count++;
            }
        }
        return count;
    }

    //Count no of digits
    static int count(int n){
     int count=0;
        while(n>1){
            n=n/10;
            count++;
        }
        return count;
    }
