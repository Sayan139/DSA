public class p15_p5_type {
    static void fun(int n){
        for(int i=n; i>=0; i--){
            for(char j='A'; j<='A'+i; j++){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(5);
    }
}
