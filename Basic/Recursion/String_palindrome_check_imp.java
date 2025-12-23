public class String_palindrome_check_imp {
    static boolean helper(String s,int start,int end){
        if(start >= end) return true;
        while(start < end && !Character.isLetterOrDigit(s.charAt(start))) start++;
        while(start < end && !Character.isLetterOrDigit(s.charAt(end))) end--;
        if(Character.toLowerCase(s.charAt(start)) != Character.toLowerCase(s.charAt(end))) return false;
        return helper(s,start+1,end-1);
    }
    static boolean isPalindrome(String s) {
        return helper(s,0,s.length()-1);
    }
    public static void main(String[] args) {
        String s = "Sayan";
        isPalindrome(s);
    }
}
