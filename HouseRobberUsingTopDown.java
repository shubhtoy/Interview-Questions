package com.company;

public class HouseRobberUsingTopDown {
    public static void main(String[] args){
        int[] a = new int[]{6,7,1,30,8,2,4};
        int[] b = new int[100];
        System.out.println(HouseRobber(a,0,b));
    }
    public static int HouseRobber(int[] houses, int index, int[] arr){
        if (index >= houses.length){
            return 0;
        }
        else{
            if (arr[index] == 0){
                int p1 = houses[index] + HouseRobber(houses,index+2,arr);
                int p2 = HouseRobber(houses,index+1,arr);
                arr[index] = Math.max(p1,p2);
            }
            return arr[index];
        }
    }
}
