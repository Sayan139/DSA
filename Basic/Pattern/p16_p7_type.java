public class p16_p7_type {
    static void fun(int n){
        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                System.out.print("  ");
            }
            for(char j='A'; j<='A'+i; j++){
                System.out.print(j + " ");
            }
            for(char j=(char)('A'+i-1); j>='A'; j--){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(5);
    }
}
