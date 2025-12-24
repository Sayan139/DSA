
import java.util.HashMap;

class frequency_of_elements_in_array{
    public static void main(String[] args) {
        int[] arr = {6,4,2,3,5,6,7,7,7,7,3,5,62,4,6,7};
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0; i<arr.length; i++){
            map.put(arr[i],map.getOrDefault(arr[i], 0)+1);
        }
        System.out.println(map);
    }
}