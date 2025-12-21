public class p17_p2_type_imp {
    static void fun(int n){
        for(int i=0; i<n; i++){
            for(char j =(char)('A' + (n - i - 1)); j <= (char)('A' + n - 1); j++){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(5);
    }
}
