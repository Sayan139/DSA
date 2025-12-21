public class p14_p2_type {
    static void fun(int n){
        for(int i=0; i<n; i++){
            for(char j = 'A'; j<='A'+i; j++){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        fun(5);
    }
}
