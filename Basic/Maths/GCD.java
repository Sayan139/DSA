public class GCD {
    // bruite force : The GCD of two numbers is the largest number that divides both of them without leaving a remainder. We iterate through all numbers from 1 up to the minimum of the two input numbers, checking if each number is a common factor of both input numbers.
    /*better approach : 
    If we iterate from the minimum of N1 and N2 down to 1, we reduce the number of iterations because we start from the potentially largest common factor and work downwards.*/
    // optimal : Euclid algo
    static int gcd(int a, int b) {
        // code here
        while(a > 0 && b > 0){
            if(a > b){
                a = a%b;
            }else{
                b = b%a;
            }
        }
        if(a == 0) return b;
        return a;
    }
    public static void main(String[] args) {
        gcd(5,6);
    }
}
