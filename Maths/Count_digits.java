class Count_digits{
    static int fun(int n){
        if (n == 0) return 1;
        n = Math.abs(n); // if the num is negative 
        return (int)(Math.log10(n) + 1);
    }
    public static void main(String[] args) {
        System.out.println(fun(5830458));
    }
}