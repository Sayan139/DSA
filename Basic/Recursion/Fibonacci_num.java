public class Fibonacci_num {
    static int fib(int n) {
        if(n<0) return 0;
        if(n==1 || n == 0) return n;
        int first = fib(n-1);
        int second = fib(n-2);
        return first + second;
    }
    public static void main(String[] args) {
        fib(6);
    }
}
