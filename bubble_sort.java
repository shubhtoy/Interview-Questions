class bubble_sort {
    public static void main(String[] args) {

        int[] arr = { 3, 10, 4, 18, 9 };

        // time complexity = O(n^2) --> (n-1)+(n-2)+......+2+1
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
