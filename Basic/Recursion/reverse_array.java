class reverse_array{
    static void helper(int arr[],int start,int end){
        if(start >= end) return;
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        helper(arr,start+1,end-1);
    }
    static void reverseArray(int arr[]) {
        helper(arr,0,arr.length-1);
    }
    public static void main(String[] args) {
        int[] arr = {5,6,7,8,8,3};
        reverseArray(arr);
    }
}