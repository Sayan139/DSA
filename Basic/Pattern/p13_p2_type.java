public class p13_p2_type {
    static void fun(int n){
        int x = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                System.out.print(x++ + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(5);
    }
}
