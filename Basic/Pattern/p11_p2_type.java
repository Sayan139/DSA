public class p11_p2_type {
    static void fun(int n){
        int x = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                if(x==1){
                    System.out.print(x);
                    x = 0;
                }else{
                    System.out.print(x);
                    x = 1;
                }
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(5);
    }
}
