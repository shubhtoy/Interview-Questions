package com.company;

public class NumberFactorUsingTopDown {
    public static void main(String[] args){
        int n = 10;

        System.out.println(NumberFactor(n));
    }
    public static int[] arr = new int[100];
    public static int NumberFactor(int n){
        if (n < 1){
            return Integer.MAX_VALUE;
        }
        else if (n==1 || n==2){
            arr[n] = 1;
            return 1;
        }
        else if (n==3){
            arr[n] = 2;
            return 2;
        }
        else if (n==4){
            arr[n] = 4;
            return 4;
        }
        else if (arr[n] != 0){
            return arr[n];
        }
        else {
            arr[n] = NumberFactor(n-1) + NumberFactor(n-3) + NumberFactor(n-4);
            return arr[n];
        }
    }
}
