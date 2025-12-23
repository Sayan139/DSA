public class Armstrong_num_check {
    static boolean armstrongNumber(int n) {
        // code here
        int org = n;
        int ans = 0;
        while(n != 0){
            int temp = n % 10;
            ans += Math.pow(temp,3);
            n /= 10;
        }return ans==org;
    }
    public static void main(String[] args) {
        armstrongNumber(151);
    }
}
