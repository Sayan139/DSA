public class p9_star {
    static void fun(int n){
        for(int i=1; i<=n; i++){
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
        for(int i=n-1; i>=1; i--){
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
