import java.util.Set;
import java.util.TreeSet;

public class All_divisors_of_a_Number{
    public static void print_divisors(int n) {
        Set<Integer> set = new TreeSet<>();
        for(int i=1; i<=Math.sqrt(n); i++){
            if(n%i == 0){
                set.add(i);
                set.add(n/i);
            }
        }
        for(int x : set){
            System.out.print(x + " ");
        }
    }
}