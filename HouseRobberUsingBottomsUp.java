package com.company;

public class HouseRobberUsingBottomsUp {
    public static void main(String[] args){
        int[] a = new int[]{6,7,1,30,8,2,4};
        System.out.println(HouseRobber(a));
    }
    public static int HouseRobber(int[] houses){
        int a = 0;
        int prev = houses[houses.length-1];
        int prev1 = houses[houses.length-2];
        for (int i = houses.length-2; i>0; i--){
            a = Math.max(prev+houses[i-1],prev1);
            prev = Math.max(prev,prev1);
            prev1 = a;
        }
        return a;
    }
}
