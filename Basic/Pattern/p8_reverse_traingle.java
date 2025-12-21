public class p8_reverse_traingle {
    static void fun(int n){
        for(int i=n; i>=1; i--){
            for(int j=n; j>=i; j--){
                System.out.print("  ");
            }
            for(int j=1; j<=i; j++){
                System.out.print("* ");
            }
            for(int j=2; j<=i; j++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(5);
    }
}
