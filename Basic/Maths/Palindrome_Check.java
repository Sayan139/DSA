public class Palindrome_Check {
    static boolean isPalindrome(int x) {
        if(x < 0) return false;
        int org = x;
        int ans = 0;
        while(x != 0){
            int temp = x % 10;
            if(ans > Integer.MAX_VALUE/10 || (ans == Integer.MAX_VALUE/10 && temp > 7)) return false;
            if(ans < Integer.MIN_VALUE/10 || (ans == Integer.MIN_VALUE/10 && temp < -8)) return false;
            ans = ans * 10 + temp;
            x /= 10;
        }return ans == org;
    }
    public static void main(String[] args) {
        isPalindrome(535);
    }
}
