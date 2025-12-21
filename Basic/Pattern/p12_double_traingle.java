public class p12_double_traingle {
    static void fun(int n){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                System.out.print(j+" ");
            }
            for(int j=n; j>=i; j--){
                System.out.print("  ");
            }
            for(int j=n-1; j>=i; j--){
                System.out.print("  ");
            }
            for(int j=i; j>=1; j--){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(4);
    }
}
